/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:23:12 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/17 14:49:35 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "ft.hpp"
#include "utils.hpp"

#include <chrono>
using namespace std::chrono;

namespace ft{
	template <class T, class Alloc = std::allocator<T> >
	class vector{
		public:
			typedef T                                     	value_type;
			typedef Alloc									allocator_type;
			
			typedef typename Alloc::reference        		reference;
			typedef typename Alloc::const_reference  		const_reference;
			typedef typename Alloc::pointer         		pointer;
			typedef typename Alloc::const_pointer    		const_pointer;
				
			typedef ft::iterator<T>               			iterator;
			typedef ft::iterator<const T> 	                const_iterator;
			typedef ft::reverse_iterator<T>       			reverse_iterator;
			typedef ft::reverse_iterator<const T> 			const_reverse_iterator;
			typedef std::ptrdiff_t                 		    difference_type;
			typedef std::size_t                     		size_type;

	
		
		private:
		    value_type     		*container;
			allocator_type 		_alloc;
			size_type      		size_v;
			size_type       	capacity_v;
		
		public:
	
	explicit vector (const allocator_type& alloc = allocator_type()){
		this->container = NULL;
		_alloc = alloc;
		size_v = 0;
		capacity_v = 0;
	}
	
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
	{
		if (n > max_size())
			throw std::length_error("vector");
		try{
		container = _alloc.allocate(n);
		for(size_type i = 0; i < n; i++){
			_alloc.construct(container + i, val);
		}
		size_v = n;
		capacity_v = n;
		}
		catch(...){
			throw std::bad_alloc();
		}
	}

	template<class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) : _alloc(alloc){
		try{
		size_type n = last - first;
		size_type i = 0;
		container = _alloc.allocate(n);
		for(InputIterator it = first; it != last; it++, i++)
			_alloc.construct(container + i, *it);
		capacity_v = n;
		size_v = n;
		}
		catch(...){
			throw std::bad_alloc();
		}
	}
	
	
	vector(const vector &copy){
		_alloc = copy._alloc;
		size_v = copy.size_v;
		capacity_v = copy.capacity_v;
		container = _alloc.allocate(capacity_v);
		for (size_type i = 0; i < size_v; i++)
			_alloc.construct(container + i, copy.container[i]);
	}

	vector &operator=(const vector &copy){
		if (*this == copy)
			return *this;
		clear();
		_alloc.deallocate(container, capacity_v);
		_alloc = copy._alloc;
		size_v = copy.size_v;
		capacity_v = copy.capacity_v;
		container = _alloc.allocate(capacity_v);
		for (size_type i = 0; i < size_v; i++)
			_alloc.construct(container + i, copy.container[i]);
		return (*this);
	}

	~vector(){
		clear();
		if (container)
			_alloc.deallocate(container, capacity_v);
	}

	void display(){
		for (size_type i = 0; i < size_v;i++)
			std::cout << *(container + i) << "\n";
	}
	
	
/************************************ Iterators *******************************************************/		

	iterator begin(){
		if (size_v > 0)
			return iterator(&container[0]);
		return iterator();
	}
	
	iterator end(){
		if (size_v > 0)
			return iterator(&container[size_v]);
		return iterator();
	}

	const_iterator begin() const{
		if (size_v > 0)
			return const_iterator(&container[0]);
		return const_iterator();
	}

	const_iterator end() const{
		if (size_v > 0)
			return const_iterator(&container[size_v]);
		return const_iterator();
	}

	reverse_iterator rbegin(){
		if (size_v > 0)
			return reverse_iterator(&container[size_v - 1]);
		return reverse_iterator();
	}

	reverse_iterator rend(){
		if (size_v > 0)
			return reverse_iterator(&container[-1]);
		return reverse_iterator();
	}

	const_reverse_iterator rbegin() const{
		if (size_v > 0)
			return const_reverse_iterator(&container[size_v - 1]);
		return const_reverse_iterator();
	}

	const_reverse_iterator rend() const{
		if (size_v > 0)
			return const_reverse_iterator(&container[-1]);
		return const_reverse_iterator();
	}

		
/************************************ Modifiers ********************************************/

	void insert(iterator pos, size_type n, const value_type &val){
		size_type ps = pos - begin();
		if ((size_type)abs(pos - begin()) > size_v)
			ps = size_v;
		reserve(size_v + n);
		size_type i = ps;
		value_type *tmp = smart_copycat(container, ps, size_v);
		for (; i < n;i++)
			_alloc.construct(container + i, val);
		if (ps < size_v){
		for (size_type j = 0; j < size_v - ps; j++, i++)
			_alloc.construct(container + i, tmp[j]);
		}
		_alloc.deallocate(tmp, size_v - ps);
		size_v += n;
		capacity_v = size_v;	
	}

	iterator insert(iterator pos, const value_type &val){
		if (size_v + 1 <= capacity_v){
			size_type n = size_v;
			for (iterator it = end(); it != pos; it--){
				_alloc.construct(container + n, container[n - 1]);
				n--;
			}
			_alloc.construct(container + n, val);
			size_v++;
			return pos;
		}
		else{
			value_type *tmp = ft::copycat(container, size_v);
			size_type n = 0;
			size_type z = size_v;
			size_type x = pos - begin();
			clear();
			for (size_type i = 0; i < x; i++)
				push_back(tmp[n++]);
			push_back(val);
			for(size_type i = x; i < z; i++)
				push_back(tmp[n++]);
			_alloc.deallocate(tmp, n - 1);
			return iterator(&container[x]);
		}
	}

	template<class InputIterator>
	void insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
		value_type *tmp = NULL;
		size_type ps = 0;
		try{
		ps = pos - begin();
		size_type n = last - first;
		size_type c = capacity_v;
		if (ps > size_v)
			ps = size_v;
		if (c == 0)
			c++;
		while (size_v + n > c)
			c *= 2;
		reserve(c);
		size_type i = ps;
		tmp = smart_copycat(container, ps, size_v);
		for (InputIterator it = first; it != last ;it++, i++)
			container[i] = *it;
		if (tmp){
			for (size_type j = 0; j < size_v - ps; j++, i++)
				_alloc.construct(container + i, tmp[j]);
			_alloc.deallocate(tmp, size_v - ps);
		}
		size_v += n;
		}
		catch(...){
			_alloc.deallocate(container, capacity_v);
			if (tmp)
				_alloc.deallocate(tmp, size_v - ps);
			capacity_v = 0;
			size_v = 0;
			container = NULL;
			throw std::bad_alloc();
		}
	}
		
	iterator erase(iterator pos){
		size_type ps = pos - begin();
		if (ps >= size_v)
			return pos;
		_alloc.destroy(&container[ps]);
		for (size_type i = ps; i < size_v - 1; i++)
			container[i] = container[i + 1];
		_alloc.destroy(&container[size_v - 1]);
		size_v--;
		return pos;
	}

	iterator erase(iterator first, iterator last){
		size_type n = last - first;
		size_type ps = first - begin();
		size_type en = end() - last;
		en = size_v - en;
		for(size_type i = ps; en < size_v ;i++, en++)
			container[i] = container[en];
		while (n--)
			pop_back();
		return first;
	}
 

	void pop_back(){
		_alloc.destroy(&container[size_v - 1]);
		size_v--;
	}
	
	void push_back(const value_type &val){
		try{
			if (size_v + 1 > capacity_v){
				value_type *tmp;
				if (capacity_v == 0)
					capacity_v = 1;
				else
					capacity_v *= 2;
				tmp = _alloc.allocate(capacity_v);
				for(size_type i = 0; i < size_v; i++){
					_alloc.construct(tmp + i, container[i]);
				}
				_alloc.construct(tmp + size_v, val);
				_alloc.deallocate(container, capacity_v);
				container = tmp;
			}
			else
				_alloc.construct(container + size_v, val);
			size_v++;
			}
		catch(...){
			throw std::bad_alloc();
		}
	}

	template<class InputIterator>
	void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
		size_type n = (last - first);
		InputIterator it = first;
		if (n <= capacity_v){
			clear();
			it = first;
			n = 0;
			while (it != last){
				_alloc.construct(container + n, *it);
				n++;
				it++;
			}
		}
		else{
			_alloc.deallocate(container, capacity_v);
			try{
				container = _alloc.allocate(n);
				it = first;
				n = 0;
				while (it != last){
					_alloc.construct(container + n, *it);
					n++;
					it++;
				}
				capacity_v = n;
			}
			catch(...){throw std::bad_alloc();}
		}
		size_v = n;
	}


	void assign(size_type n, const value_type &val){
		if (n > max_size())
			throw std::length_error("vector");
		if (n <= capacity_v){
			size_type i = size_v;
			while (i--)
				pop_back();
			while (++i < n)
				_alloc.construct(container + i, val);
		}
		else{
			_alloc.deallocate(container, capacity_v);
			try{
				container = _alloc.allocate(n);
				for(size_type i = 0; i < n; i++){
					_alloc.construct(container + i, val);
				}
				capacity_v = n;
			}
			catch(...){throw std::bad_alloc();}
		}
		size_v = n;
	}

	void clear(){
		for(size_type i = size_v; i > 0;i--){
			pop_back();
		}
		size_v = 0;
	}

	void swap(vector &x){
		value_type *tmp = this->container;
		size_type size_tmp = size_v;
		size_type capacity_tmp = capacity_v;

		this->container = x.container;
		this->size_v = x.size_v;
		this->capacity_v = x.capacity_v;

		x.container = tmp;
		x.size_v = size_tmp;
		x.capacity_v = capacity_tmp;
	}


/********************************** Capacity ******************************/

	size_type size() const{
		return (size_v);
	}
	
	size_type max_size() const{
		return (_alloc.max_size());
	}
	
	size_type capacity() const{
		return (capacity_v);
	}

	bool empty() const{
		if (size_v == 0)
			return true;
		return false;
	}
	
	void resize(size_type n, value_type val = value_type()){
		if (n > max_size())
			throw std::length_error("vector");
		if (n == size_v)
			return ;
		if (n > size_v){
			for(size_type  i = size_v; i < n;i++){
				push_back(val);
			}
		}
		else{
			for(size_type i = size_v; i > n; i--){
				pop_back();
			}
		}
		size_v = n;	
	}
	
	void reserve(size_type n){
		if (n > max_size())
			throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
		if (n <= capacity_v)
			return ;
		value_type *tmp;
		tmp = _alloc.allocate(n);
		for(size_type i = 0; i < size_v; i++){
			_alloc.construct(tmp + i, container[i]);
		}
		_alloc.deallocate(container, capacity_v);
		capacity_v = n;
		container = tmp;
	}

/*********************************** Element access ************************************/
	
	reference &operator[](difference_type i){
		return (container[i]);
	}

	const_reference &operator[](difference_type i) const{
		return (container[i]);
	}
	
	reference at(size_type n){
		if (n >= size_v)
			throw std::out_of_range("vector");
		return (container[n]);
	}
	
	const_reference at(size_type n) const{
		if (n < 0 || n >= size_v)
			throw std::out_of_range("vector");
		return (container[n]);
	}

	reference front(){
		return (container[0]);
	}
	
	const_reference front() const {
		return (container[0]);
	}

	reference back(){
		return (container[size_v - 1]);
	}

	const_reference back() const{
		return (container[size_v - 1]);
	}

	value_type *data(){
		return (container);
	}


	};

	template <class T, class Alloc>
	bool operator==(const vector <T, Alloc>& lhs, const vector <T, Alloc>& rhs){
		if (lhs.size() != rhs.size())
      		return false;
		for (size_t i = 0; i < lhs.size(); i++){
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
  	}

	template <class T, class Alloc>
	bool operator!=(const vector <T, Alloc>& lhs, const vector <T, Alloc>& rhs){
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector <T, Alloc>& lhs, const vector <T, Alloc>& rhs){
		size_t i = 0;
		while (i < lhs.size() && i < rhs.size()){
			if (lhs[i] < rhs[i])
				return true;
			else if (lhs[i] > rhs[i])
				return false;
			i++;
		}
		if (i == lhs.size() && i != rhs.size())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<=(const vector <T, Alloc>& lhs, const vector <T, Alloc>& rhs){
		return ((lhs < rhs) || (lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector <T, Alloc>& lhs, const vector <T, Alloc>& rhs){
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector <T, Alloc>& lhs, const vector <T, Alloc>& rhs){
		return ((rhs < lhs) || (lhs == rhs));
	}
	
	template <class T, class Alloc>
	void swap(vector <T, Alloc>& x, vector <T, Alloc>& y){
		x.swap(y);
	}

	




	
};




#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:23:12 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/14 15:59:15 by bboulhan         ###   ########.fr       */
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
		    value_type      *container;
			Alloc 			alloc;
			size_type       size_v;
			size_type       capacity_v;
		
		public:
	
	explicit vector (const Alloc& _alloc = Alloc()){
		this->container = NULL;
		alloc = _alloc;
		size_v = 0;
		capacity_v = 0;
	}
	
	explicit vector (size_type n, const value_type& val = value_type(), const Alloc& _alloc = Alloc())
	{
		(void)_alloc;
		if (n > max_size())
			throw std::length_error("vector");
		try{
		container = alloc.allocate(n);
		for(size_type i = 0; i < n; i++){
			alloc.construct(container + i, val);
		}
		size_v = n;
		capacity_v = n;
		}
		catch(...){
			throw std::bad_alloc();
		}
	}

	template<class InputIterator>
	vector(InputIterator first, InputIterator last, const Alloc& _alloc = Alloc(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0){
		(void)_alloc;
		try{
		size_type n = last - first;
		size_type i = 0;
		container = alloc.allocate(n);
		for(InputIterator it = first; it != last; it++, i++)
			alloc.construct(container + i, *it);
		capacity_v = n;
		size_v = n;
		}
		catch(...){
			throw std::bad_alloc();
		}
	}
	
	
	vector(const vector &copy){
		alloc = copy.alloc;
		size_v = copy.size_v;
		capacity_v = copy.capacity_v;
		container = alloc.allocate(capacity_v);
		for (size_type i = 0; i < size_v; i++)
			alloc.construct(container + i, copy.container[i]);
	}

	vector &operator=(const vector &copy){
		if (*this == copy)
			return *this;
		clear();
		alloc.deallocate(container, capacity_v);
		alloc = copy.alloc;
		size_v = copy.size_v;
		capacity_v = copy.capacity_v;
		container = alloc.allocate(capacity_v);
		for (size_type i = 0; i < size_v; i++)
			alloc.construct(container + i, copy.container[i]);
		return (*this);
	}

	~vector(){
		clear();
		if (container)
			alloc.deallocate(container, capacity_v);
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
		// if (size_v > 0)
			return const_iterator(&container[0]);
		// return const_iterator();
	}

	const_iterator end() const{
		// if (size_v > 0)
			return const_iterator(&container[size_v]);
		// return const_iterator();
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

	// const_reverse_iterator rbegin() const{
	// 	if (size_v > 0)
	// 		return const_reverse_iterator(&container[size_v - 1]);
	// 	return const_reverse_iterator();
	// }

	// const_reverse_iterator rend() const{
	// 	if (size_v > 0)
	// 		return const_reverse_iterator(&container[-1]);
	// 	return const_reverse_iterator();
	// }
	



		

		
/************************************ Modifiers ********************************************/

	void insert(iterator pos, size_type n, const value_type &val){
		size_type ps = pos - begin();
		if ((size_type)abs(pos - begin()) > size_v)
			ps = size_v;
		reserve(size_v + n);
		size_type i = ps;
		value_type *tmp = smart_copycat(container, ps, size_v);
		for (; i < n;i++)
			alloc.construct(container + i, val);
		if (ps < size_v){
		for (size_type j = 0; j < size_v - ps; j++, i++)
			alloc.construct(container + i, tmp[j]);
		}
		alloc.deallocate(tmp, size_v - ps);
		size_v += n;
		capacity_v = size_v;	
	}

	iterator insert(iterator pos, const value_type &val){
		if (size_v + 1 <= capacity_v){
			size_type n = size_v;
			for (iterator it = end(); it != pos; it--){
				alloc.construct(container + n, container[n - 1]);
				n--;
			}
			alloc.construct(container + n, val);
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
			alloc.deallocate(tmp, n - 1);
			return iterator(&container[x]);
		}
	}

	template<class inIter>
	void insert(iterator pos, inIter first, inIter last, typename ft::enable_if<!ft::is_integral<inIter>::value>::type* = 0){
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
		for (inIter it = first; it != last ;it++, i++)
			container[i] = *it;
		if (tmp){
			for (size_type j = 0; j < size_v - ps; j++, i++)
				alloc.construct(container + i, tmp[j]);
			alloc.deallocate(tmp, size_v - ps);
		}
		size_v += n;
		}
		catch(...){
			alloc.deallocate(container, capacity_v);
			if (tmp)
				alloc.deallocate(tmp, size_v - ps);
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
		alloc.destroy(&container[ps]);
		for (size_type i = ps; i < size_v - 1; i++)
			container[i] = container[i + 1];
		alloc.destroy(&container[size_v - 1]);
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
		alloc.destroy(&container[size_v - 1]);
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
				tmp = alloc.allocate(capacity_v);
				for(size_type i = 0; i < size_v; i++){
					alloc.construct(tmp + i, container[i]);
				}
				alloc.construct(tmp + size_v, val);
				alloc.deallocate(container, capacity_v);
				container = tmp;
			}
			else
				alloc.construct(container + size_v, val);
			size_v++;
			}
		catch(...){
			throw std::bad_alloc();
		}
	}

	template<class inIter>
	void assign(inIter first, inIter last, typename ft::enable_if<!ft::is_integral<inIter>::value>::type* = 0){
		size_type n = (last - first);
		inIter it = first;
		if (n <= capacity_v){
			clear();
			it = first;
			n = 0;
			while (it != last){
				alloc.construct(container + n, *it);
				n++;
				it++;
			}
		}
		else{
			alloc.deallocate(container, capacity_v);
			try{
				container = alloc.allocate(n);
				it = first;
				n = 0;
				while (it != last){
					alloc.construct(container + n, *it);
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
				alloc.construct(container + i, val);
		}
		else{
			alloc.deallocate(container, capacity_v);
			try{
				container = alloc.allocate(n);
				for(size_type i = 0; i < n; i++){
					alloc.construct(container + i, val);
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
		// auto start = high_resolution_clock::now();
		value_type *tmp = this->container;
		size_type size_tmp = size_v;
		size_type capacity_tmp = capacity_v;
		// vector tmp = *this;
		// *this = x;
		// x = tmp;

 
		
		this->container = x.container;
		this->size_v = x.size_v;
		this->capacity_v = x.capacity_v;

		x.container = tmp;
		x.size_v = size_tmp;
		x.capacity_v = capacity_tmp;
		// auto stop = high_resolution_clock::now();
		// auto duration = duration_cast<microseconds>(stop - start);
		// std::cout << duration.count() << std::endl;
		// std::cout<< "--------------------------------------------------\n";
		// std::cout << "tmp : " << &(*tmp) << "\n";
		// std::cout << "container  : " << &(*container) << "\n";
		// std::cout << "copy x : " << &(*x.container) << "\n";
	}


/********************************** Capacity ******************************/

	size_type size() const{
		return (size_v);
	}
	
	size_type max_size() const{
		return (alloc.max_size());
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
		tmp = alloc.allocate(n);
		for(size_type i = 0; i < size_v; i++){
			alloc.construct(tmp + i, container[i]);
		}
		alloc.deallocate(container, capacity_v);
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
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector <T, Alloc>& lhs, const vector <T, Alloc>& rhs){
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector <T, Alloc>& lhs, const vector <T, Alloc>& rhs){
		return !(lhs < rhs);
	}
	
	template <class T, class Alloc>
	void swap(vector <T, Alloc>& x, vector <T, Alloc>& y){
		x.swap(y);
	}
	
	




	
};




#endif
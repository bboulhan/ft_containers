/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:23:12 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/09 16:27:15 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "ft.hpp"

namespace ft{
	template <class T, class Alloc = std::allocator<T> >
	class vector{
		public:
			typedef T                                     	value_type;
			// typedef Alloc 									allocator_type;
			
			typedef typename Alloc::reference        		reference;
			typedef typename Alloc::const_reference  		const_reference;
			typedef typename Alloc::pointer         		pointer;
			typedef typename Alloc::const_pointer    		const_pointer;

			// typedef ft::vector_iterator<T>               iterator;
			// typedef ft::vector_iterator<T, true>         const_iterator;
			// typedef ft::reverse_iterator<iterator>       reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef std::ptrdiff_t                  difference_type;
			typedef std::size_t                     size_type;
		
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
		try{
		container = alloc.allocate(n);
		for(int i = 0; i < n; i++){
			alloc.construct(container + i, val);
		}
		size_v = n;
		capacity_v = n;
		}
		catch(...){
			throw std::bad_alloc();
		}
	}
	// template <class itr> vector (itr first, itr last, const Alloc& _alloc = Alloc());
	
	vector(const vector &copy){
		container = copy.container;
		alloc = copy.alloc;
		size_v = copy.size_v;
		capacity_v = copy.capacity_v;
	}

	vector &operator=(const vector &copy){
		container = copy.container;
		alloc = copy.alloc;
		size_v = copy.size_v;
		capacity_v = copy.capacity_v;
		return (*this);
	}
		
/************************************ Modifiers ********************************************/	

	
	void pop_back(){
		// value_type *tmp;
		// tmp = alloc.allocate(size_v - 1);
		// for(int i = 0; i < size_v - 1; i++){
		// 	alloc.construct(tmp + i, container[i]);
		// }
		// alloc.deallocate(container, size_v);
		alloc.destroy(&container[size_v - 1]);
		size_v--;
		// container = tmp;
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
				for(int i = 0; i < size_v; i++){
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

/********************************** Capacity ******************************/

	size_type size() const{
		return (size_v);
	}
	
	size_type max_size() const{
		return (alloc.max_size());
	}
	
	value_type capacity() const{
		return (capacity_v);
	}

	bool empty() const{
		if (size_v == 0)
			return true;
		return false;
	}
	
	void resize(size_type n, value_type val = value_type()){
		if (n < 0 || n > max_size())
			throw std::length_error("vector");
		if (n == size_v)
			return ;
		if (n > size_v){
			for(int  i = size_v; i < n;i++){
				push_back(val);
			}
		}
		else{
			for(int i = size_v; i > n; i--){
				pop_back();
			}
		}
		size_v = n;	
	}
	
	void shrink_to_fit(){
		if (size_v == capacity_v)
			return ;
		try{
		value_type *tmp;
		tmp = alloc.allocate(size_v);
		for(int i = 0; i < size_v; i++){
			alloc.construct(tmp + i, container[i]);
		}
		alloc.deallocate(container, capacity_v);
		capacity_v = size_v;
		container = tmp;
		}
		catch(...){
			throw std::bad_alloc();
		}
	}
	
	void reserve(size_type n){
		if (n > max_size() || n < 0)
			throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
		if (n <= capacity_v)
			return ;
		value_type *tmp;
		tmp = alloc.allocate(n);
		for(int i = 0; i < size_v; i++){
			alloc.construct(tmp + i, container[i]);
		}
		alloc.deallocate(container, capacity_v);
		capacity_v = n;
		container = tmp;
	}

/*********************************** Element access ************************************/
	
	value_type &operator[](unsigned int i){
		return (container[i]);
	}
	
	reference at(size_type n){
		if (n < 0 || n >= size_v)
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
};




#endif
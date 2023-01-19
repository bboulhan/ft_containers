/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:41 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/19 18:02:21 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <cmath>
#include <unistd.h>

namespace ft{

	int get_capacity(int x){
		int a = 0;
		int y = 0;
		while (x > 1){
			y++;
			a += x % 2;
			x = x / 2;
		}
		if (a > 0)
			y++;
		return (pow(2, y));
	}

	template<class T>
	T *add(T *data, T elem, unsigned int size){
		std::allocator<T> alloc;
		T *tmp;
		if (size == 0){
			tmp = alloc.allocate(1);
			alloc.construct(tmp, elem);
			return tmp;
		}
		tmp = alloc.allocate(size + 1);
		for(unsigned int i = 0; i < size; i++)
			alloc.construct(tmp + i, data[i]);
		alloc.construct(tmp + size, elem);
		alloc.deallocate(data, size);
		return tmp;
	}

	template<class T>
	T *copycat(T *data, unsigned int size){
		std::allocator<T> alloc;
		T *copy_cat;
		copy_cat = alloc.allocate(size);
		for (unsigned int i = 0; i < size; i++)
			alloc.construct(copy_cat + i, data[i]);
		return copy_cat;		
	}

	template<class T>
	class iterator{
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::random_access_iterator_tag iterator_category;
		private:
			pointer 	ptr;
		public:
			iterator() {ptr = NULL;}
			iterator(const iterator &src){ *this = src;}
			iterator(pointer container) : ptr(container) {}
			
			iterator &operator=(const iterator &op){
				this->ptr = op.ptr;
				return *this;
			}

			iterator &operator++(){
				++ptr;
				return *this;
			}

			iterator operator++(int){
				iterator tmp(*this);
				++(*this);
				return tmp;
			}

			iterator &operator--(){
				--ptr;
				return *this;
			}

			iterator operator--(int){
				iterator tmp(*this);
				--(*this);
				return tmp;
			}
			
			reference operator*(){
				return *this->ptr;
			}

			pointer operator->(){
				return this->ptr;
			}
			
			bool operator!=(const iterator &comp){
				if (this->ptr != comp.ptr)
					return true;
				return false;
			}

			bool operator==(const iterator &comp){
				if (this->ptr == comp.ptr)
					return true;
				return false;
			}

			bool operator<(const iterator &comp){
				if (this->ptr < comp.ptr)
					return true;
				return false;
			}

			bool operator>(const iterator &comp){
				if (this->ptr > comp.ptr)
					return true;
				return false;
			}

			bool operator<=(const iterator &comp){
				if (this->ptr <= comp.ptr)
					return true;
				return false;
			}

			bool operator>=(const iterator &comp){
				if (this->ptr >= comp.ptr)
					return true;
				return false;
			}

			iterator operator+(difference_type n){
				return iterator(this->ptr + n);
			}

			iterator operator-(difference_type n){
				return iterator(this->ptr - n);
			}
			
			difference_type operator-(const iterator &op){
				difference_type n = 0;
				pointer p = this->ptr;
				if (this->ptr < op.ptr){
					while (p++ != op.ptr)
						n--;
				}
				else{
					while (p-- != op.ptr)
						n++;
				}
				return n;
			}

			iterator &operator+=(difference_type n){
				this->ptr = this->ptr + n;
				return *this;
			}
			
			iterator &operator-=(difference_type n){
				this->ptr = this->ptr - n;
				return *this;
			}
			
			value_type operator[](difference_type n){
				return (this->ptr[n]);
			}

			
			
			
		
		
	};
	
		
}
















































// namespace ft
// {
// 	template <class T>
// 	class iterator
// 	{
// 		public:
// 			typedef T value_type;
// 			typedef T* pointer;
// 			typedef T& reference;
// 			typedef std::ptrdiff_t difference_type;
// 			typedef std::random_access_iterator_tag iterator_category;

// 			iterator() : _ptr(NULL) {}
// 			iterator(pointer ptr) : _ptr(ptr) {}
// 			iterator(const iterator &src) { *this = src; }
// 			~iterator() {}

// 			iterator &operator=(const iterator &rhs)
// 			{
// 				if (this != &rhs)
// 					this->_ptr = rhs._ptr;
// 				return (*this);
// 			}

// 			reference operator*() const { return (*this->_ptr); }
// 			pointer operator->() const { return (this->_ptr); }

// 			iterator &operator++() { this->_ptr++; return (*this); }
// 			iterator operator++(int) { iterator tmp(*this); operator++(); return (tmp); }
// 			iterator &operator--() { this->_ptr--; return (*this); }
// 			iterator operator--(int) { iterator tmp(*this); operator--(); return (tmp); }

// 			iterator operator+(difference_type n) const { return (iterator(this->_ptr + n)); }
// 			iterator operator-(difference_type n) const { return (iterator(this->_ptr - n)); }
// 			iterator &operator+=(difference_type n) { this->_ptr += n; return (*this); }
// 			iterator &operator-=(difference_type n) { this->_ptr -= n; return (*this); }

// 			reference operator[](difference_type n) const { return (*(this->_ptr + n)); }

// 			friend bool operator==(const iterator &lhs, const iterator &rhs) { return (lhs._ptr == rhs._ptr); }
// 			friend bool operator!=(const iterator &lhs, const iterator &rhs) { return (lhs._ptr != rhs._ptr); }
// 			friend bool operator<(const iterator &lhs, const iterator &rhs) { return (lhs._ptr < rhs._ptr); }
// 			friend bool operator<=(const iterator &lhs, const iterator &rhs) { return (lhs._ptr <= rhs._ptr); }
// 			friend bool operator>(const iterator &lhs, const iterator &rhs) { return (lhs._ptr > rhs._ptr); }
// 			friend bool operator>=(const iterator &lhs, const
// 	};

#endif
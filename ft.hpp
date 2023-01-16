/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:41 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/16 17:52:53 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <cmath>

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
			iterator(pointer container) : ptr(container) {
			// 	std::cout << *ptr << "\tcontainer : " << *container << "\n";
			}
			
			iterator &operator=(const iterator &op){
				this->ptr = op.ptr;
				// std::cout << *ptr << "\t op : " << *op.ptr << "\n";
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
			
			bool operator!=(const iterator &comp){
				if (this->ptr != comp.ptr)
					return true;
				return false;
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
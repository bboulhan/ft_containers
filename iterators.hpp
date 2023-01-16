/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:08:26 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/16 15:52:10 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include <iostream>


namespace ft{

	template<class T>
	class iterators{
		


		
	};
















	
}




#endif































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
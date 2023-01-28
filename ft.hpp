/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:41 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/28 13:42:29 by bboulhan         ###   ########.fr       */
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
	T *smart_copycat(T *data, int begin, int end){
		std::allocator<T> alloc;
		T *Smart_Copycat;
		Smart_Copycat = alloc.allocator(end - begin);
		for (int i = begin; i <= end; i++)
			alloc.construct(Smart_Copycat + i, data[i]);
		return Smart_Copycat;
	}

	template<class InIter1, class InIter2>
	bool equal(InIter1 first1, InIter1 last1, InIter2 first2){
		while (first1 != last1){
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template<class InIter1, class InIter2, class binPre>
	bool equal(InIter1 first1, InIter1 last1, InIter2 first2, binPre pred){
		while (first1 != last1){
			if (!pred(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}
	
	template<class T1, class T2>
	struct pair{
		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;
		
		pair(): first(T1()), second(T2()){}
		pair(const first_type &a, const second_type &b): first(a), second(b){}
		
		template<class U, class V>
		pair(const pair<U, V> &pr): first(pr.first), second(pr.second){}
		pair &operator=(const pair &pr){
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	template<class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template<class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
		return !(lhs == rhs);
	}

	template<class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template<class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
		return !(rhs < lhs);
	}

	template<class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
		return (rhs < lhs);
	}

	template<class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
		return !(lhs < rhs);
	}

	template<class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y){
		return (pair<T1, T2>(x, y));
	}
	
	
	


	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <typename T>
	struct is_integral { static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<short> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long> { static const bool value = true; };

	template <>
	struct is_integral<long long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long> { static const bool value = true; };


	
		
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
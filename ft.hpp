/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:41 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/18 19:22:04 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <unistd.h>
#include <cstddef>



namespace ft{




	


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
		if (size == 0)
			return NULL;
		std::allocator<T> alloc;
		T *copy_cat;
		copy_cat = alloc.allocate(size);
		for (unsigned int i = 0; i < size; i++)
			alloc.construct(copy_cat + i, data[i]);
		return copy_cat;
	}

	template<class T>
	T *smart_copycat(T *data, size_t begin, size_t end){
		std::allocator<T> alloc;
		size_t n = end - begin;
		if (n == 0 || alloc.max_size() < n)
			return NULL;
		T *Smart_Copycat;
		Smart_Copycat = alloc.allocate(n);
		for (size_t i = 0; i + begin < end; i++)
			alloc.construct(Smart_Copycat + i, data[i + begin]);
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

		operator T1() const {
			return first;
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

	template<class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2){
		while (first1 != last1){
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
	
	template<typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef std::forward_iterator_tag iterator_category;
	};

	template<typename T>
	struct iterator_traits<T*> {
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<typename T>
	struct iterator_traits<const T*> {
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
	
	// template <class T>
	// class iterator_traits {
	// public:
	// 	typedef typename T::iterator_category iterator_category;
	// 	typedef typename T::value_type         value_type;
	// 	typedef typename T::pointer            pointer;
	// 	typedef typename T::reference          reference;
	// 	typedef typename std::ptrdiff_t       difference_type;
	// };
	// template<class T>
	// class iterator_traits<T*> {
	// public:
	// 	typedef std::random_access_iterator_tag iterator_category;
	// 	typedef T                               value_type;
	// 	typedef T*                              pointer;
	// 	typedef T&                              reference;
	// 	typedef std::ptrdiff_t                  difference_type;
	// };
	
	// template<class T>
	// class iterator_traits<const T*> {
	// public:
	// 	typedef std::random_access_iterator_tag iterator_category;
	// 	typedef const T                               value_type;
	// 	typedef const T*                              pointer;
	// 	typedef const T&                              reference;
	// 	typedef std::ptrdiff_t                  difference_type;
	// };



}


#endif
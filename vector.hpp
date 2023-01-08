/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:23:12 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/08 16:02:35 by bboulhan         ###   ########.fr       */
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
			size_type       size;
			size_type       capacity;
		
		public:
	
	explicit vector (const Alloc& _alloc = Alloc()){
		this->container = NULL;
		alloc = _alloc;
		size = 0;
		capacity = 0;
	}
	explicit vector (size_type n, const value_type& val = value_type(), const Alloc& _alloc = Alloc())
	{
		container = alloc.allocate(n);
		for(int i = 0; i < n; i++){
			alloc.construct(container + i, val);
		}
		size = 0;
		capacity = 0;
	}
	template <class itr> vector (itr first, itr last, const Alloc& _alloc = Alloc());
	
	vector(const vector &copy){
		container = copy.container;
		
	}

	};
};


#endif
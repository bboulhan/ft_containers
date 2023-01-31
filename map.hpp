/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:35:14 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/31 18:38:50 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "RedBlackTree.hpp"
#include "ft.hpp"
#include "map_utils.hpp"

namespace ft{

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map{
		public:
			typedef 									Key key_type;
			typedef 									T mapped_type;
			typedef 									ft::pair<Key,T> value_type;
			typedef 									Compare key_compare;
			// typedef value_compare (Compare c) : comp(c) {}

			typedef typename ft::RedBlackTree<value_type, Compare, Alloc>::iterator iterator;

			typedef typename Alloc::size_type       	size_type;//A type that counts the number of elements in a vector.
			typedef typename Alloc::difference_type 	difference_type;//A type that provides the difference between the addresses of two elements in a vector.
			typedef typename Alloc::pointer         	pointer;//A type that provides a pointer to a component of a vector.
			typedef typename Alloc::const_pointer   	const_pointer;//A t
			typedef typename Alloc::reference       	reference;//A type that provides a reference to an element stored in a vector.
			typedef typename Alloc::const_reference 	const_reference;
			typedef RedBlackTree<value_type, Compare, Alloc> RedBlackTree;
		
		
		// private:
			RedBlackTree tree;
			Alloc alloc;
			
			
		public:
			// explicit map(const key_compare& comp = key_compare(), const Alloc& alloc = Alloc()) : tree(comp, alloc) {}
			map() : tree() {}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const Alloc& alloc = Alloc()) : tree(comp, alloc) {
				while (first != last)
				{
					tree.insert(*first);
					first++;
				}
			}
	
			~map() {}

			map(const map& copy) : tree(copy.tree) {}

			map& operator=(const map& copy) {
				tree = copy.tree;
				return *this;
			}
			
	/******************************************** Iterators *******************************************************************/	

		iterator begin() {
			return iterator(tree.first_elem()->data);
		}


	/********************************************* Capacity ******************************************************************/	

		bool empty() const {
			if (tree.size() == 0)
				return true;
			return false;
		}

		size_type size() const {
			return tree.size();
		}

		size_type max_size() const {
			return alloc.max_size();
		}
	
	/********************************************* Element access ******************************************************************/

		
		
	};

};





#endif
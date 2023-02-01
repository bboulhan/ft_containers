/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:35:14 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/01 18:55:57 by bboulhan         ###   ########.fr       */
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
			typedef typename ft::RedBlackTree<value_type, Compare, Alloc>::node		node;
			typedef typename Alloc::size_type       					size_type;//A type that counts the number of elements in a vector.
			typedef typename Alloc::difference_type					 	difference_type;//A type that provides the difference between the addresses of two elements in a vector.
			typedef typename Alloc::pointer         					pointer;//A type that provides a pointer to a component of a vector.
			typedef typename Alloc::const_pointer  					 	const_pointer;//A t
			typedef typename Alloc::reference       					reference;//A type that provides a reference to an element stored in a vector.
			typedef typename Alloc::const_reference 					const_reference;
			typedef 		 RedBlackTree<value_type, Compare, Alloc>	RedBlackTree;
		
		
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
			return iterator(tree.first_elem());
		}

		iterator end() {
			return iterator(tree.nil);
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

		// mapped_type &operator[](const key_type& k) {
		// 	iterator(tree.search(ft::pair<key_type, mapped_type>(k, nullptr)));
		// }
		

	/*********************************************** Modifiers ***********************************************************************/

		ft::pair<iterator, bool> insert(const value_type &val){
			node *tmp = tree.search(val);
			if (tmp)
				return ft::pair<iterator, bool>(iterator(tmp), false);
			if (!tmp)
			tmp = tree.insert(val);
			return ft::pair<iterator, bool>(iterator(tmp), true);
		}

		iterator insert(iterator position, const value_type& val) {
			node *tmp = tree.search(val);
			if (tmp)
				return iterator(tmp);
			tmp = tree.insert(val);
			return iterator(tmp);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			InputIterator tmp = first;
			while (tmp != last)
			{
				tree.insert(*tmp);
				tmp++;
			}
		}

		void erase(iterator position) {
			tree.Delete(*position);
		}

		size_type erase(const key_type& k) {			
			value_type val(k, mapped_type());
			node *tmp = tree.search(val);
			if (!tmp)
				return 0;
			tree.Delete(val);
			return 1;
		}

		void erase(iterator first, iterator last) {
			iterator tmp = first;
			while (tmp != last)
			{
				tree.Delete(*tmp);
				tmp++;
			}
		}

		void swap(map& x) {
			RedBlackTree tmp = tree;
			tree = x.tree;
			x.tree = tmp;
		}


		
		

	/*********************************************** Operations ************************************************************/

		iterator find(const key_type& k) {
			value_type val(k, mapped_type());
			node *tmp = tree.search(val);
			if (!tmp)
				return end();
			return iterator(tmp);
		}
		
		// size_type count(const key_type& k) const {
		// 	const iterator tmp = find(k);
		// 	if (find(k) == end())
		// 		return 0;
		// 	return 1;
		// }
	
		iterator lower_bound(const key_type& k) {
			iterator tmp = begin();
			while (tmp != end())
			{
				if (tmp->first >= k)
					return tmp;
				tmp++;
			}
			return end();
		}

		iterator upper_bound(const key_type& k) {
			iterator tmp = begin();
			while (tmp != end())
			{
				if (tmp->first > k)
					return tmp;
				tmp++;
			}
			return end();
		}

		ft::pair<iterator,iterator> equal_range(const key_type& k) {
			return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}

		Alloc get_allocator() const {
			return alloc;
		}
		
		void clear() {
			tree.deleter();
		}

	/*********************************************** Observers ************************************************************/
	
		
	};

};





#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:35:14 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/11 18:02:58 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "RedBlackTree.hpp"
#include "ft.hpp"

namespace ft{

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map{
		public:
			typedef 									Key key_type;
			typedef 									T mapped_type;
			typedef 									ft::pair<const Key,T> value_type;
			typedef 									Compare key_compare;
			// typedef value_compare (Compare c) : comp(c) {}

			typedef typename ft::RedBlackTree<value_type, Compare, Alloc>::iterator 		iterator;
			// typedef typename ft::RedBlackTree<value_type, Compare, Alloc>::const_iterator	const_iterator;
			
			typedef typename ft::RedBlackTree<value_type, Compare, Alloc>::reverse_iterator reverse_iterator;
			typedef typename ft::RedBlackTree<value_type, Compare, Alloc>::node		node;
			typedef typename Alloc::size_type       					size_type;//A type that counts the number of elements in a vector.
			typedef typename Alloc::difference_type					 	difference_type;//A type that provides the difference between the addresses of two elements in a vector.
			typedef typename Alloc::pointer         					pointer;//A type that provides a pointer to a component of a vector.
			typedef typename Alloc::const_pointer  					 	const_pointer;//A t
			typedef typename Alloc::reference       					reference;//A type that provides a reference to an element stored in a vector.
			typedef typename Alloc::const_reference 					const_reference;
			typedef 		 RedBlackTree<value_type, Compare, Alloc>	RedBlackTree;
		
		
		private:
			RedBlackTree tree;
			Alloc alloc;
			
			
		public:
			// explicit map(const key_compare& comp = key_compare(), const Alloc& alloc = Alloc()) : tree(comp, alloc) {}
			map() : tree() {}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const Alloc& alloc = Alloc()) : tree() {
				(void)comp;
				(void)alloc;
				while (first != last)
				{
					tree.insert(*first);
					first++;
				}
			}
	
			~map() {}

			map(const map& copy) : tree(copy.tree), alloc(copy.alloc) {}

			map& operator=(const map& copy){
				tree = copy.tree;
				alloc = copy.alloc;
				return *this;
			}

			void display(){
				tree.display_map(tree.get_root(), 0);
			}

			
			
	/******************************************** Iterators *******************************************************************/	

		iterator begin() {
			if (tree.get_root())
				return iterator(tree.first_elem());
			return (iterator(tree.get_nil()));
		}

		iterator end() {
			return iterator(tree.get_nil());
		}

		reverse_iterator rbegin() {
			if (tree.get_root())
				return reverse_iterator(tree.last_elem()->parent);
			return (reverse_iterator(tree.get_nil()));
		}

		reverse_iterator rend() {
			return (reverse_iterator(tree.get_nil()));
		}

		// const_iterator begin() const {
		// 	if (tree.get_root())
		// 		return const_iterator(tree.first_elem());
		// 	return (const_iterator(tree.get_nil()));
		// }

		// const_iterator end() const {
		// 	return const_iterator(tree.get_nil());
		// }



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

		mapped_type& operator[] (const key_type& k) {
			value_type val(k, mapped_type());
			node *tmp = tree.find(val);
			if (!tmp)
				tmp = tree.insert(val);
			return tmp->data->second;
		}
		

	/*********************************************** Modifiers ***********************************************************************/

		ft::pair<iterator, bool> insert(const value_type &val){
			node *tmp = tree.find(val);
			if (tmp)
				return ft::pair<iterator, bool>(iterator(tmp), false);
			if (!tmp)
			tmp = tree.insert(val);
			return ft::pair<iterator, bool>(iterator(tmp), true);
		}

		iterator insert(iterator position, const value_type& val) {
			(void)position;
			node *tmp = tree.find(val);
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
			node *tmp = tree.find(val);
			if (!tmp)
				return 0;
			tree.Delete(*tmp->data);
			return 1;
		}

		void erase(iterator first, iterator last) {
			iterator tmp = first;
			iterator tmp2 = tmp;
			while (tmp != last)
			{	
				tmp2 = tmp;
				tmp++;
				tree.Delete(*tmp2);
			}
		}

		void swap(map& x) {
			RedBlackTree tmp(tree);
			tree = x.tree;
			x.tree = tmp;
		}

		void clear() {
			if (!tree.get_root())
				return;
			tree.deleter();
		}
		
		

	/*********************************************** Operations ************************************************************/

		iterator find(const key_type& k) {
			value_type val(k, mapped_type());
			node *tmp = tree.find(val);
			if (!tmp)
				return end();
			return iterator(tmp);
		}
		
		size_type count(const key_type& k) const {
			value_type val(k, mapped_type());
			node *tmp = tree.find(val);
			if (!tmp)
				return 0;
			return 1;
		}
	
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

		// const_iterator lower_bound(const key_type& k) const {
		// 	const_iterator tmp = begin();
		// 	while (tmp != end())
		// 	{
		// 		if (tmp->first >= k)
		// 			return tmp;
		// 		tmp++;
		// 	}
		// 	return end();
		// }

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
		
	
	/*********************************************** Observers ************************************************************/
	
		
	};

	template<class key, class T, class Compare, class Alloc>
	void swap(map<key, T, Compare, Alloc>& x, map<key, T, Compare, Alloc>& y) {
		x.swap(y);
	}

	// template<class Key, class T, class Compare, class Alloc>
	// bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {
	// 	if (lhs.size() != rhs.size())
	// 		return false;
	// 	// map<Key, T, Compare, Alloc>::iterator 
		
		
	// 	map<Key, T, Compare, Alloc>::iterator tmp;
	// 	tmp = lhs.begin();
	// 	map<Key, T, Compare, Alloc>::iterator tmp2;
	// 	tmp2 = rhs.begin();
	// 	while (tmp != lhs.end())
	// 	{
	// 		if (*tmp != *tmp2)
	// 			return false;
	// 		tmp++;
	// 		tmp2++;
	// 	}
	// 	return true;
	// }

	// template<class key, class T, class Compare, class Alloc>
	// bool operator!=(const map<key, T, Compare, Alloc>& lhs, const map<key, T, Compare, Alloc>& rhs) {
	// 	return !(lhs == rhs);
	// }

	// template<class key, class T, class Compare, class Alloc>
	// bool operator<(const map<key, T, Compare, Alloc>& lhs, const map<key, T, Compare, Alloc>& rhs) {
	// 	typename map<key, T, Compare, Alloc>::const_iterator tmp = lhs.begin();
	// 	typename map<key, T, Compare, Alloc>::const_iterator tmp2 = rhs.begin();
	// 	while (tmp != lhs.end() && tmp2 != rhs.end())
	// 	{
	// 		if (*tmp < *tmp2)
	// 			return true;
	// 		if (*tmp > *tmp2)
	// 			return false;
	// 		tmp++;
	// 		tmp2++;
	// 	}
	// 	if (tmp == lhs.end() && tmp2 != rhs.end())
	// 		return true;
	// 	return false;
	// }


};





#endif
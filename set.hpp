/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:00:11 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/18 16:00:35 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "ft.hpp"
#include "RedBlackTree.hpp"
#include "map_iterators.hpp"


namespace ft{
	template<class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set{
		public:
			typedef T 				key_type;
			typedef T 				value_type;
			typedef Compare 		key_compare;
			typedef Alloc 			allocator_type;

			typedef typename ft::map_iterator<value_type, node<value_type> > iterator;
			typedef typename ft::map_iterator<const value_type, node<value_type> > const_iterator;

			typedef typename ft::map_reverse_iterator<value_type, node<value_type> > reverse_iterator;
			typedef typename ft::map_reverse_iterator<const value_type, node<value_type> > const_reverse_iterator;
			
			
			typedef typename ft::RedBlackTree<value_type, Compare, Alloc>::node		node;
			typedef typename Alloc::size_type       					size_type;
			typedef typename Alloc::difference_type					 	difference_type;
			typedef typename Alloc::pointer         					pointer;
			typedef typename Alloc::const_pointer  					 	const_pointer;
			typedef typename Alloc::reference       					reference;
			typedef typename Alloc::const_reference 					const_reference;
			typedef 		 RedBlackTree<value_type, Compare, Alloc>	RedBlackTree;
		
		private:
			RedBlackTree tree;
			allocator_type _alloc;
			key_compare comp;
			
		public:
			explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): tree(comp, alloc), _alloc(alloc){};

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : tree(comp, alloc), _alloc(alloc){
				while (first != last)
				{
					tree.insert(*first);
					first++;
				}
			};

			set(const set &x): tree(x.tree), _alloc(x._alloc){};
			
			~set(){};

			set &operator=(const set &x){
				tree = x.tree;
				_alloc = x._alloc;
				return (*this);
			};

			void display(){
				tree.display_set(tree.get_root(), 0);
			};

	/*********************************************** Iterators ******************************************************************/

			iterator begin(){
				if (tree.get_root())
					return iterator(tree.first_elem());
				return (iterator(tree.get_nil()));
			};

			iterator end(){
				return (iterator(tree.get_nil()));
			};

			const_iterator begin() const{
				if (tree.get_root())
					return const_iterator(tree.first_elem());
				return (const_iterator(tree.get_nil()));
			};

			const_iterator end() const{
				return (const_iterator(tree.get_nil()));
			};

			reverse_iterator rbegin() {
				if (tree.get_root())
					return reverse_iterator(tree.last_elem()->parent);
				return (reverse_iterator(tree.get_nil()));
			}

			reverse_iterator rend() {
				return (reverse_iterator(tree.get_nil()));
			}

			const_reverse_iterator rbegin() const {
				if (tree.get_root())
					return const_reverse_iterator(tree.last_elem()->parent);
				return (const_reverse_iterator(tree.get_nil()));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(tree.get_nil()));
			}
			

	/********************************************** Capacity ****************************************************************************/
			
			bool empty() const{
				if (tree.size() == 0)
					return (true);
				return (false);
			};
			
			size_type size() const{
				return (tree.size());
			};
			
			size_type max_size() const{
				return (_alloc.max_size());
			};		

	/********************************************** Modifiers ****************************************************************************/

			ft::pair<iterator,bool> insert(const value_type &val){
				node *tmp = tree.search(val);
				if (tmp)
					return ft::pair<iterator, bool>(iterator(tmp), false);
				if (!tmp)
					tmp = tree.insert(val);
				return ft::pair<iterator, bool>(iterator(tmp), true);
			};

			iterator insert(iterator position, const value_type &val){
				(void)position;
				node *tmp = tree.search(val);
				if (tmp)
					return iterator(tmp);
				tmp = tree.insert(val);
				return iterator(tmp);
			};

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last){
				InputIterator tmp = first;
				while (tmp != last)
				{
					tree.insert(*tmp);
					tmp++;
				}
			};

			void erase(iterator position){
				tree.Delete(*position);
			};

			size_type erase(const value_type &val){
				node *tmp = tree.search(val);
				if (!tmp)
					return (0);
				tree.Delete(val);
				return (1);
			};

			void erase(iterator first, iterator last){
				iterator tmp = first;
				iterator tmp2 = tmp;
				while (tmp != last)
				{	
					tmp2 = tmp;
					tmp++;
					tree.Delete(*tmp2);
				}
			};

			void swap(set &x){
				RedBlackTree tmp(tree);
				tree = x.tree;
				x.tree = tmp;
			}

			void clear() {
				tree.deleter();
			}

	/*********************************************** Operations ************************************************************/

		iterator lower_bound(const key_type& k) {
			iterator tmp = begin();
			while (tmp != end())
			{
				if (comp(k, *tmp) || k == *tmp)
					return tmp;
				tmp++;
			}
			return end();
		}
		
		const_iterator lower_bound(const key_type& k) const {
			const_iterator tmp = begin();
			while (tmp != end())
			{
				if (comp(k, *tmp) || k == *tmp)
					return tmp;
				tmp++;
			}
			return end();
		}
				
		iterator upper_bound(const key_type& k) {
			iterator tmp = begin();
			while (tmp != end())
			{
				if (comp(k, *tmp))
					return tmp;
				tmp++;
			}
			return end();
		}

		const_iterator upper_bound(const key_type& k) const {
			const_iterator tmp = begin();
			while (tmp != end())
			{
				if (comp(k, *tmp))
					return tmp;
				tmp++;
			}
			return end();
		}

		iterator find(const key_type& k) {
			node *tmp = tree.search(k);
			if (!tmp)
				return end();
			return iterator(tmp);
		}

		size_type count(const key_type& k) const {
			node *tmp = tree.search(k);
			if (!tmp)
				return 0;
			return 1;
		}
	
		ft::pair<iterator,iterator> equal_range(const key_type& k) {
			return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}

		Alloc get_allocator() const {
			return _alloc;
		}

		key_compare key_comp() const {
			return comp;
		}
	
	};

	template <class Key, class Compare, class Alloc>
	bool operator==(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		typename set<Key, Compare, Alloc>::const_iterator tmp = lhs.begin();
		typename set<Key, Compare, Alloc>::const_iterator tmp2 = rhs.begin();
		while (tmp != lhs.end())
		{
			if (*tmp != *tmp2)
				return false;
			tmp++;
			tmp2++;
		}
		return true;
	}

	template <class Key, class Compare, class Alloc>
	bool operator!=(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
		typename set<Key, Compare, Alloc>::const_iterator tmp = lhs.begin();
		typename set<Key, Compare, Alloc>::const_iterator tmp2 = rhs.begin();
		while (tmp != lhs.end() && tmp2 != rhs.end())
		{
			if (*tmp < *tmp2)
				return true;
			if (*tmp > *tmp2)
				return false;
			tmp++;
			tmp2++;
		}
		if (tmp == lhs.end() && tmp2 != rhs.end())
			return true;
		return false;
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
		return ((lhs < rhs) || (lhs == rhs));
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
		return (rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs){
		return ((rhs < lhs) || (lhs == rhs));
	}

	template <class Key, class Compare, class Alloc>
	void swap(set<Key,Compare,Alloc>& x, set<Key,Compare,Alloc>& y){
		x.swap(y);
	}


}







#endif
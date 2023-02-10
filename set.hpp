/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:00:11 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/10 15:56:34 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "ft.hpp"
#include "RedBlackTree.hpp"


namespace ft{
	template<class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set{
		public:
			typedef T key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename ft::RedBlackTree<value_type, Compare, Alloc>::iterator iterator;
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
			allocator_type alloc;
			
		public:
			// explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): tree(comp, alloc), alloc(alloc){};
			set(): tree(), alloc(){};

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()){
				(void)comp;
				(void)alloc;
				while (first != last)
				{
					tree.insert(*first);
					first++;
				}
			};

			set(const set &x): tree(x.tree), alloc(x.alloc){};
			
			~set(){};

			set &operator=(const set &x){
				tree = x.tree;
				alloc = x.alloc;
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
				return (alloc.max_size());
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
				if (*tmp >= k)
					return tmp;
				tmp++;
			}
			return end();
		}
		
		iterator upper_bound(const key_type& k) {
			iterator tmp = begin();
			while (tmp != end())
			{
				if (*tmp > k)
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
	
		ft::pair<iterator,iterator> equal_range(const key_type& k) {
			return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}

		Alloc get_allocator() const {
			return alloc;
		}
	
	};


};









#endif
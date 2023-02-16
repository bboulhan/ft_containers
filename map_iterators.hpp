/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:49:31 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/16 18:33:00 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef map_iterators_HPP
# define map_iterators_HPP

#include "ft.hpp"
#include "RedBlackTree.hpp"

namespace ft{

		template<class T, class node >
		class map_iterator{
			public:
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef node* base;
				typedef std::ptrdiff_t difference_type;
				typedef std::random_access_iterator_tag iterator_category;
			
			private:
				base 	ptr;		
				
			public:
				map_iterator() {ptr = NULL;}
				map_iterator(const map_iterator &src){ *this = src;}
				map_iterator(base container) : ptr(container) {}
										
				operator map_iterator<const T, node >() const{
					return map_iterator<const T, node >(ptr);
				}	

				map_iterator &operator=(const map_iterator &op){
					this->ptr = op.ptr;
					return *this;
				}
				
				pointer operator->() const{
					return this->ptr->data;
				}
		
				reference operator*() const{
					return *this->ptr->data;
				}
		
				map_iterator &operator++(){
					ptr = next(ptr);
					return *this;
				}
	
				map_iterator operator++(int){
					map_iterator tmp = *this;
					ptr = next(ptr);
					return tmp;
				}

				map_iterator operator--(){
					ptr = prev(ptr);
					return *this;
				}

				map_iterator operator--(int){
					map_iterator tmp = *this;
					ptr = prev(ptr);
					return tmp;
				}

				bool operator==(const map_iterator &op) const{
					return (this->ptr->data == op.ptr->data);
				}

				bool operator!=(const map_iterator &op) const{
					return (this->ptr->data != op.ptr->data);
				}
		};

		template<class T, class node >
		class map_reverse_iterator{
			public:
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef node* base;
				typedef std::ptrdiff_t difference_type;
				typedef std::random_access_iterator_tag iterator_category;
			
			private:
				base 	ptr;
			public:
				map_reverse_iterator() {ptr = NULL;}
				map_reverse_iterator(const map_reverse_iterator &src){ *this = src;}
				map_reverse_iterator(base container) : ptr(container){}

				operator map_reverse_iterator<const T, node >() const{
					return map_reverse_iterator<const T, node >(ptr);
				}

				map_reverse_iterator &operator=(const map_reverse_iterator &op){
					this->ptr = op.ptr;
					
					return *this;
				}

				pointer operator->() const{
					return this->ptr->data;
				}

				reference operator*() const{
					return *this->ptr->data;
				}

				map_reverse_iterator &operator++(){
					ptr = prev(ptr);
					return *this;
				}

				map_reverse_iterator operator++(int){
					map_reverse_iterator tmp = *this;
					ptr = prev(ptr);
					return tmp;
				}

				map_reverse_iterator operator--(){
					if (ptr && ptr->nil)
						ptr = ptr->right;
					else
						ptr = next(ptr);
					return *this;
				}

				map_reverse_iterator operator--(int){
					map_reverse_iterator tmp = *this;
					if (ptr && ptr->nil)
						ptr = ptr->right;
					else
						ptr = next(ptr);
					return tmp;
				}

				bool operator==(const map_reverse_iterator &op) const{
					return (this->ptr->data == op.ptr->data);
				}

				bool operator!=(const map_reverse_iterator &op) const{
					return (this->ptr->data != op.ptr->data);
				}
		};






	
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:38:16 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/13 20:49:06 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "stack.hpp"


namespace ft{
	
	template<class T>
	class iterator : public std::iterator<std::random_access_iterator_tag , T>{
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::random_access_iterator_tag iterator_category;

		public:
			pointer 	ptr;
			iterator() {ptr = NULL;}
			iterator(const iterator &src) : ptr(src.ptr){}
			iterator(pointer container) : ptr(container) {}
			
			iterator &operator=(const iterator &op){
				this->ptr = op.ptr;
				return *this;
			}

			iterator &operator++(){
				++ptr;
				return *this;
			}

			iterator operator++(int){
				iterator tmp(*this);
				++(*this);
				return tmp;
			}

			iterator &operator--(){
				--ptr;
				return *this;
			}

			iterator operator--(int){
				iterator tmp(*this);
				--(*this);
				return tmp;
			}
			
			reference operator*(){
				return *this->ptr;
			}

			pointer operator->(){
				return this->ptr;
			}
			
			bool operator!=(const iterator &comp){
				if (this->ptr != comp.ptr)
					return true;
				return false;
			}

			bool operator==(const iterator &comp){
				if (this->ptr == comp.ptr)
					return true;
				return false;
			}

			bool operator<(const iterator &comp){
				if (this->ptr < comp.ptr)
					return true;
				return false;
			}

			bool operator>(const iterator &comp){
				if (this->ptr > comp.ptr)
					return true;
				return false;
			}

			bool operator<=(const iterator &comp){
				if (this->ptr <= comp.ptr)
					return true;
				return false;
			}

			bool operator>=(const iterator &comp){
				if (this->ptr >= comp.ptr)
					return true;
				return false;
			}

			iterator operator+(difference_type n){
				return iterator(this->ptr + n);
			}

			iterator operator-(difference_type n){
				return iterator(this->ptr - n);
			}
			
			difference_type operator-(const iterator &op){
				difference_type n = 0;
				pointer p = this->ptr;
				if (this->ptr < op.ptr){
					while (p++ != op.ptr)
						n--;
				}
				else{
					while (p-- != op.ptr)
						n++;
				}
				return n;
			}

			iterator &operator+=(difference_type n){
				this->ptr = this->ptr + n;
				return *this;
			}
			
			iterator &operator-=(difference_type n){
				this->ptr = this->ptr - n;
				return *this;
			}
			
			value_type operator[](difference_type n){
				return (this->ptr[n]);
			}
		};

		
		
		


		template<class T>
		class const_iterator : public std::iterator<std::random_access_iterator_tag , T>{
			public :
				typedef  const T value_type;
				// typedef	value_type const&   reference;
                // typedef	value_type const&	const_reference;
                // typedef	value_type const*   pointer;
				typedef  const T* pointer;
				typedef  const T& reference;
				typedef std::ptrdiff_t difference_type;
				typedef std::random_access_iterator_tag iterator_category;
			
			
			public:
			    pointer 	ptr;
			
				 const_iterator() {ptr = NULL;}
				 const_iterator(const const_iterator &src) : ptr(src.ptr){}
				 const_iterator(pointer container) : ptr(container) {}
				// explicit const_iterator(const iterator<T> &src) {ptr = src.ptr;}

				const_iterator &operator=(const const_iterator &op){
					this->ptr = op.ptr;
					return *this;
				}

				const_iterator &operator++(){
					++this->ptr;
					return *this;
				}

				const_iterator operator++(int){
					const_iterator tmp(*this);
					++(*this);
					return tmp;
				}

				const_iterator &operator--(){
					--this->ptr;
					return *this;
				}

				const_iterator operator--(int){
					const_iterator tmp(*this);
					--(*this);
					return tmp;
				}
				
				reference operator*(){
					return *this->ptr;
				}
				
				pointer operator->(){
					return this->ptr;
				}

				const_iterator operator+(difference_type n){
					return const_iterator(this->ptr + n);
				}

				const_iterator operator-(difference_type n){
					return const_iterator(this->ptr - n);
				}

				difference_type operator-(const const_iterator &op){
					difference_type n = 0;
					pointer p = this->ptr;
					if (this->ptr < op.ptr){
						while (p++ != op.ptr)
							n--;
					}
					else{
						while (p-- != op.ptr)
							n++;
					}
					return n;
				}
				
				value_type operator[](difference_type n){
					return (this->ptr[n]);
				}

				bool operator!=(const const_iterator &comp){
					if (this->ptr != comp.ptr)
						return true;
					return false;
				}

				bool operator==(const const_iterator &comp){
					if (this->ptr == comp.ptr)
						return true;
					return false;
				}

				bool operator<(const const_iterator &comp){
					if (this->ptr < comp.ptr)
						return true;
					return false;
				}

				bool operator>(const const_iterator &comp){
					if (this->ptr > comp.ptr)
						return true;
					return false;
				}

				bool operator<=(const const_iterator &comp){
					if (this->ptr <= comp.ptr)
						return true;
					return false;
				}

				bool operator>=(const const_iterator &comp){
					if (this->ptr >= comp.ptr)
						return true;
					return false;
				}

				const_iterator &operator+=(difference_type n){
					this->ptr = this->ptr + n;
					return *this;
				}

				const_iterator &operator-=(difference_type n){
					this->ptr = this->ptr - n;
					return *this;
				}

		};
				

			
		
	template<class T>
	class reverse_iterator{
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::random_access_iterator_tag iterator_category;
		private:
			pointer 	ptr;
		public:
			reverse_iterator() {ptr = NULL;}
			reverse_iterator(const reverse_iterator &src){ *this = src;}
			reverse_iterator(pointer container) : ptr(container) {}
			
			reverse_iterator &operator=(const reverse_iterator &op){
				this->ptr = op.ptr;
				return *this;
			}

			reverse_iterator &operator++(){
				--ptr;
				return *this;
			}

			reverse_iterator operator++(int){
				reverse_iterator tmp(*this);
				++(*this);
				return tmp;
			}

			reverse_iterator &operator--(){
				++ptr;
				return *this;
			}

			reverse_iterator operator--(int){
				reverse_iterator tmp(*this);
				--(*this);
				return tmp;
			}
			
			reference operator*(){
				return *this->ptr;
			}

			pointer operator->(){
				return this->ptr;
			}
			
			bool operator!=(const reverse_iterator &comp){
				if (this->ptr != comp.ptr)
					return true;
				return false;
			}

			bool operator==(const reverse_iterator &comp){
				if (this->ptr == comp.ptr)
					return true;
				return false;
			}

			bool operator<(const reverse_iterator &comp){
				if (this->ptr < comp.ptr)
					return true;
				return false;
			}

			bool operator>(const reverse_iterator &comp){
				if (this->ptr > comp.ptr)
					return true;
				return false;
			}

			bool operator<=(const reverse_iterator &comp){
				if (this->ptr <= comp.ptr)
					return true;
				return false;
			}

			bool operator>=(const reverse_iterator &comp){
				if (this->ptr >= comp.ptr)
					return true;
				return false;
			}

			reverse_iterator operator+(difference_type n){
				return reverse_iterator(this->ptr - n);
			}

			reverse_iterator operator-(difference_type n){
				return reverse_iterator(this->ptr + n);
			}
			
			difference_type operator-(const reverse_iterator &op){
				difference_type n = 0;
				pointer p = this->ptr;
				if (this->ptr < op.ptr){
					while (p++ != op.ptr)
						n++;
				}
				else{
					while (p-- != op.ptr)
						n--;
				}
				return n;
			}

			reverse_iterator &operator+=(difference_type n){
				this->ptr = this->ptr - n;
				return *this;
			}

			reverse_iterator &operator-=(difference_type n){
				this->ptr = this->ptr + n;
				return *this;
			}

			value_type operator[](difference_type n){
				return (this->ptr - n);
			}
	};

}



#endif
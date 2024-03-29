/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:38:16 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/18 19:40:08 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft{
	
	template<class T>
	class iterator : public std::iterator<std::random_access_iterator_tag , T>{
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::random_access_iterator_tag iterator_category;
			typedef iterator_category iterator_type;
		private:
			pointer 	ptr;
		public:

			pointer base() const {return ptr;}
			iterator() {ptr = NULL;}
			iterator(const iterator &src) : ptr(src.base()){}
			iterator(pointer container) : ptr(container) {}
			
			operator iterator<const T>() const{
				return iterator<const T>(ptr);
			}
			
			
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
	class reverse_iterator{
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::random_access_iterator_tag iterator_category;
			typedef iterator_category iterator_type;
		private:
			pointer 	ptr;
		public:
			pointer base() const{return ptr;}			
			
			reverse_iterator() {ptr = NULL;}
			reverse_iterator(const reverse_iterator &src){ *this = src;}
			reverse_iterator(pointer container) : ptr(container) {}
			
			template<class B>
			reverse_iterator(const reverse_iterator<B> &src){ *this = src;}
			
			

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
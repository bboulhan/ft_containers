/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:46:15 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/22 19:53:16 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "ft.hpp"
#include "vector.hpp"

namespace ft{
	template<class T, class base = ft::vector<T> >
	class stack{
		public:
			typedef T 				value_type;
			typedef base			container_type;
			typedef size_t 			size_type;
		
		private:
			container_type container;
		
		public:
			explicit stack(const container_type &ctrn = container_type()){
				this->container = ctrn;
			}

			value_type &top(){
				return (&container[0]);
			}	
			
			const value_type top() const{
				return (&container[0]);
			}

			void push(const value_type &val){
				container.push_back(val);
			}

			void pop(){
				container.pop_back();
			}

			size_type size() const{
				return (container.size());
			}

			bool empty() const{
				return (container.empty());
			}
	};

	
}



#endif

























		// public:
		// 	typedef T value_type;
		// 	typedef Container container_type;
		// 	typedef size_t size_type;
		// private:
		// 	container_type _container;
		// public:
		// 	explicit stack(const container_type &ctnr = container_type()) : _container(ctnr) {}
		// 	bool empty() const {return _container.empty();}
		// 	size_type size() const {return _container.size();}
		// 	value_type &top() {return _container.back();}
		// 	const value_type &top() const {return _container.back();}
		// 	void push(const value_type &val) {_container.push_back(val);}
		// 	void pop() {_container.pop_back();}
		// 	template <class T1, class Container1>
		// 	friend bool operator==(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		// 	template <class T1, class Container1>
		// 	friend bool operator!=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		// 	template <class T1, class Container1>
		// 	friend bool operator<(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		// 	template <class T1, class Container1>
		// 	friend bool operator<=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		// 	template <class T1, class Container1>
		// 	friend bool operator>(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
		// 	template <class T1, class Container1>
		// 	friend bool operator>=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
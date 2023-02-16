/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:46:15 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/16 18:31:15 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "ft.hpp"
#include "vector.hpp"
// #include "operators.hpp"

namespace ft{	

	template<class T, class Container = ft::vector<T> >
	class stack{
		public:
			typedef T 				value_type;
			typedef Container		container_type;
			typedef size_t 			size_type;
		
		private:
			container_type container;
		
		public:
			explicit stack(const container_type &ctrn = container_type()) : container(ctrn){}

			value_type &top(){
				return (container[container.size() - 1]);
			}	
			
			const value_type top() const{
				return (container[0]);
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

			bool friend operator== (const stack<T, Container> &lhs, const stack<T, Container> &rhs){
				return (lhs.container == rhs.container);
			};

			bool friend operator< (const stack<T, Container> &lhs, const stack<T, Container> &rhs){
				return (lhs.container < rhs.container);
			};
	};


	template<class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs){
		return (lhs.container == rhs.container);
	}

	template<class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){
		return (!(lhs == rhs));
	}

	template<class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs){
		return (lhs.container < rhs.container);
	}

	template<class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){
		return ((lhs < rhs) || (lhs == rhs));
	}

	template<class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs){
		return (rhs < lhs);
	}

	template<class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs){
		return ((lhs > rhs) || (lhs == rhs));
	}

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
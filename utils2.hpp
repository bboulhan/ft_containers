/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:49:31 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/13 20:50:37 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_HPP
# define UTILS2_HPP

#include "ft.hpp"
#include "stack.hpp"

namespace {

	template<class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs){
		return (lhs.container == rhs.container);
	}








	
};

#endif
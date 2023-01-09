/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:41 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/09 15:10:40 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <cmath>

namespace ft{

	int get_capacity(int x){
		int a = 0;
		int y = 0;
		while (x > 1){
			y++;
			a += x % 2;
			x = x / 2;
		}
		if (a > 0)
			y++;
		return (pow(2, y));
	}

	
		
}


#endif
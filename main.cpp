/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/11 13:54:56 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
	std::vector<int> p;
	for (int i = 1; i < 15; i++)
		p.push_back(i);
	
	try{
	std::vector<int> ab(p.begin(), p.end());

	// std::vector<int>::iterator it = ab.begin();
	std::vector<int>::reverse_iterator it = ab.rbegin();
	
	
	// it = ab.begin();
	while (it != ab.rend()){
		std::cout << *it << std::endl;
		it++;
	}
	
	std::cout << "---------------------\n";
	std::cout << ab.size() << "\t" << ab.capacity() << "\n";
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "###################################\n";
/***************************************************************************************************************/
		
	try{
	ft::vector<int> a(p.begin(), p.end());

	
	ft::vector<int>::reverse_iterator it = a.rbegin();
	// ft::vector<int>::iterator it = a.begin();
	// ft::vector<int>::const_iterator it = a.begin();


	// it = a.begin();
	while (it != a.rend()){
		std::cout << *it << std::endl;
		it++;
	}
	
	std::cout << "---------------------\n";
	
	std::cout << a.size() << "\t" << a.capacity() << "\n";
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	// system("leaks a.out");
}
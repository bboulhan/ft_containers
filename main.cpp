/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/08 14:51:57 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
	std::vector<int> p;
	for (int i = 1; i < 10; i++)
		p.push_back(i);
	
	try{
	std::vector<int> ab(p.begin(), p.end());

	std::vector<int>::iterator it = ab.begin();
	
	while (it != ab.end()){
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
	ft::vector<int>b(a);
	ft::vector<int>c(10, 2);
	
	b.resize(10);
	
	ft::vector<int>::iterator it = a.begin();


	while (it != a.end()){
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
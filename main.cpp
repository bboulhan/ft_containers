/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/17 20:05:04 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
	// std::vector<int> p;
	// p.push_back(10);
	// p.push_back(11);
	// p.push_back(12);
	// p.push_back(13);
	// p.push_back(13);
	
	// try{
	// std::vector<int> ab;
	// ab.push_back(55);
	// ab.push_back(56);
	// ab.push_back(57);
	// ab.push_back(58);
	// ab.push_back(59);

	// ab.assign(p.begin(), p.end());
	

	// std::vector<int>::iterator it = ab.begin();
	// std::vector<int>::iterator ite = ab.end();
	
	// std::cout << it[2] << "\n";
	

	
	// while (it != ite){
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	
	// std::cout << "---------------------\n";
	// std::cout << ab.size() << "\t" << ab.capacity() << "\n";

	// }
	// catch(std::exception &e){
	// 	std::cout << e.what() << std::endl;
	// }

	std::cout << "###################################\n";
/***************************************************************************************************************/
		
	try{
	ft::vector<int> a;

	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);

	

	ft::vector<int>::iterator it = a.begin();

	a.insert(it, 100);
	ft::vector<int>::iterator ab = a.begin();

	ft::vector<int>::iterator ite = a.end();

	while (ab != ite){
		std::cout << *it << std::endl;
		it++;
	}

	// a.resize(4);


	// for (int i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << std::endl;
	
	std::cout << "---------------------\n";
	
	std::cout << a.size() << "\t" << a.capacity() << "\n";
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}		
	// system("leaks a.out");
}
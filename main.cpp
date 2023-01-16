/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/15 16:42:44 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
	try{
	std::vector<int> p;
	p.push_back(10);
	p.push_back(11);
	p.push_back(12);
	p.push_back(13);
	p.push_back(14);

	p.assign(22, 22);
	p.clear();

	std::vector<int>::iterator it = p.begin();

	while (it != p.end()){
		std::cout << *it << std::endl;
		it++;
	}
	
	std::cout << "---------------------\n";
	std::cout << p.size() << "\t" << p.capacity() << "\n";

	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "###################################\n";
/***************************************************************************************************************/
		
	try{
	ft::vector<int> a;

	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	

	a.assign(22, 22);
	a.clear();



	// a.resize(4);


	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	
	std::cout << "---------------------\n";
	
	std::cout << a.size() << "\t" << a.capacity() << "\n";
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}		
	// system("leaks a.out");
}
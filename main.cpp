/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/09 15:33:56 by bboulhan         ###   ########.fr       */
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
	p.push_back(14);
	p.push_back(14);
	p.push_back(14);
	p.push_back(14);
	p.push_back(14);
	p.push_back(14);
	p.push_back(14);
	p.push_back(14);

	p.resize(4);
	p.resize(4);
	
	std::vector<int>::iterator it = p.begin();

	while (it != p.end()){
		std::cout << *it << std::endl;
		it++;
	}
	
	std::cout << "---------------------\n";
	std::cout << p.size() << "\t" << p.capacity() << "\n";

	std::cout << p[5000] << std::endl;
	std::cout << "###################################\n";


	ft::vector<int> a;

	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(13);
	a.push_back(13);
	a.push_back(13);
	a.push_back(13);

	// a.resize(4);


	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	
	std::cout << "---------------------\n";
	
	std::cout << a.size() << "\t" << a.capacity() << "\n";
	std::cout << a[5000] << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}		
	// system("leaks a.out");
}
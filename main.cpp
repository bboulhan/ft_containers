/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/18 20:18:31 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
	std::vector<int> p(6,4);
	// p.push_back(10);
	// p.push_back(11);
	// p.push_back(12);
	// p.push_back(13);
	// p.push_back(13);
	
	try{
	std::vector<int> ab(5, 5);
	// ab.push_back(55);
	// ab.push_back(56);
	// ab.push_back(57);
	// ab.push_back(58);
	// ab.push_back(59);

	

	std::vector<int>::iterator it = ab.begin();

	ab.insert(it, p.begin(), p.end());
	
	// it = ab.insert(it, 100);
	// it = ab.insert(it, 200);
	// it = ab.insert(it, 300);
	// it = ab.insert(it, 400);
	
	it = ab.begin();
	
	
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
		
	/*try{
	ft::vector<int> a(4,5);

	// a.push_back(55);
	// a.push_back(56);
	// a.push_back(57);
	// a.push_back(58);
	// a.push_back(59);
	
	

	ft::vector<int>::iterator it = a.begin();

	a.insert(it, p.begin(), p.end());
	
	// a.insert(it, 100);
	// a.insert(it, 200);
	// it = a.insert(it, 300);
	// it = a.insert(it, 400);
	
	it = a.begin();

	while (it != a.end()){
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
	// system("leaks a.out");*/
}
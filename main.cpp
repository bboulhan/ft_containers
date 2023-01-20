/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/20 19:22:08 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
	std::vector<int> p(11,4);
	p.push_back(10);
	// p.push_back(11);
	// p.push_back(12);
	
	try{
	std::vector<int> ab(1, 1);
	ab.push_back(55);
	ab.push_back(56);
	ab.push_back(57);
	ab.push_back(58);
	ab.push_back(59);
	ab.push_back(60);
	ab.push_back(61);

	std::vector<int>::iterator it = ab.begin();

	// ab.insert(it, p.begin(), p.end());
	
	// ab.insert(it + 2, 10, 22);
	
	// it = ab.insert(it +2, 100);
	// it = ab.insert(it + 1, 200);
	
	// it = ab.insert(it+3, 300);
	// // it = ab.insert(it, 400);
	// it = ab.insert(it+ 4 , 500);
	
	// it = ab.erase(it + 2);
	// it = ab.erase(it);
	// it = ab.erase(it);
	// it = ab.erase(it);
	it = ab.erase(it , it +3);
	it = ab.erase(it , it +2);
	it = ab.begin();


	// ab.erase(it + 2, ab.end());
	
	// it = ab.begin();
	
	
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
	ft::vector<int> a(1,1);

	a.push_back(55);
	a.push_back(56);
	a.push_back(57);
	a.push_back(58);
	a.push_back(59);
	a.push_back(60);
	a.push_back(61);
	ft::vector<int>::iterator it = a.begin();
	
	// it = a.erase(it +2);
	// it = a.erase(it);
	// it = a.erase(it);
	// it = a.erase(it);
	
	it = a.erase(it , it +3);
	it = a.erase(it , it +2);
	it = a.begin();

	// a.insert(it, p.begin(), p.end());
	// it = a.insert(it + 2, 100);
	// it = a.insert(it + 1, 200);
	// a.insert(it, 12, 22);
	// it = a.insert(it + 3, 300);
	// it = a.insert(it, 400);
	// it = a.insert(it+ 4 , 500);

	
	while (it != a.end()){
		std::cout << *it << std::endl;
		it++;
	}

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
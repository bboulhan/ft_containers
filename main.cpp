/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/22 17:41:22 by bboulhan         ###   ########.fr       */
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
	std::vector<int> ab;
	for (int i = 11; i < 20; i++)
		ab.push_back(i);

	std::vector<int>::iterator it = ab.begin();

	ab.insert(it, p.begin(), p.end());
	
	it = ab.begin();
	ab.insert(it + 2, 10, 22);
	
	// it = ab.insert(it +2, 100);
	// it = ab.insert(it + 1, 200);
	
	// it = ab.insert(it+3, 300);
	// // it = ab.insert(it, 400);
	// it = ab.insert(it+ 4 , 500);
	
	// it = ab.erase(it + 2);
	// it = ab.erase(it);
	// it = ab.erase(it);
	// it = ab.erase(it);
	// it = ab.erase(it , it +3);
	// it = ab.erase(it , it +2);
	// it = ab.begin();


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
	ft::vector<int> a;

	for (int i = 11; i < 20; i++)
		a.push_back(i);

	ft::vector<int>::iterator it = a.begin();
	
	// it = a.erase(it +2);
	// it = a.erase(it);
	// it = a.erase(it);
	// it = a.erase(it);
	
	// it = a.erase(it , it +3);
	// it = a.erase(it , it +2);
	// it = a.begin();

	a.insert(it, p.begin(), p.end());
	it = a.begin();
	a.insert(it + 2, 10, 22);
	// it = a.insert(it + 2, 100);
	// it = a.insert(it + 1, 200);
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
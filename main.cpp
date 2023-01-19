/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/19 19:42:47 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
	std::vector<int> p(3,4);
	p.push_back(10);
	p.push_back(11);
	p.push_back(12);
	// p.push_back(13);
	// p.push_back(13);


	try{
	std::vector<int> ab(3, 5);
	ab.push_back(55);
	ab.push_back(56);
	ab.push_back(57);
	// ab.push_back(58);
	// ab.push_back(59);

	

	std::vector<int>::iterator it = ab.begin();

	// ab.insert(it, p.begin(), p.end());
	// ab.insert(it + 2, 10, 22);
	
	it = ab.insert(it +2, 100);
	it = ab.insert(it + 1, 200);
	// it = ab.insert(it-3, 300);
	// it = ab.insert(it, 400);
	// it = ab.insert(it+ 4 , 500);
	// it = ab.insert(it, 600);
	// it = ab.insert(it, 700);
	
	
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
	ft::vector<int> a(3,5);

	a.push_back(55);
	a.push_back(56);
	a.push_back(57);
	// a.push_back(58);
	// a.push_back(59);
	
	

	ft::vector<int>::iterator it = a.begin();

	// a.insert(it, p.begin(), p.end());
	
	a.insert(it, 10, 22);
	// it = a.insert(it + 2, 100);
	// it = a.insert(it + 1, 200);
	// it = a.insert(it - 3, 300);
	// it = a.insert(it, 400);
	// it = a.insert(it+ 4 , 500);
	// it = a.insert(it, 600);
	// it = a.insert(it, 700);
	
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
	}*/
	// system("leaks a.out");
}
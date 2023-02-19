/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:12:08 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/19 16:26:55 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "map.hpp"
#include "stack.hpp"
#include "set.hpp"
#include <map>
#include <set>
#include <stack>


// std::multiplies<int>
// std::greater<int>
void map(){
	ft::map<int, std::string, std::multiplies<int> > ab;
	
	ab.insert(ft::pair<int, std::string>(20, "A11"));
	ab.insert(ft::pair<int, std::string>(15, "B15"));
	ab.insert(ft::pair<int, std::string>(8, "C8"));
	ab.insert(ft::pair<int, std::string>(23, "D23"));
	ab.insert(ft::pair<int, std::string>(33, "E13"));
	ab.insert(ft::pair<int, std::string>(9, "F9"));
	ab.insert(ft::pair<int, std::string>(55, "G1"));
	ab.insert(ft::pair<int, std::string>(10, "H10"));
	ab.insert(ft::pair<int, std::string>(40, "I40"));
	ab.insert(ft::pair<int, std::string>(18, "K12"));
	ab.insert(ft::pair<int, std::string>(50, "J50"));
	ab.insert(ft::pair<int, std::string>(12, "L20"));
	ab.insert(ft::pair<int, std::string>(7, "WE7"));
	ab.insert(ft::pair<int, std::string>(70, "OUB4"));
	ab.insert(ft::pair<int, std::string>(65, "WQQ65"));
	ab.insert(ft::pair<int, std::string>(45, "UI45"));

	ft::map<int, std::string>::reverse_iterator it = ab.rbegin();

	while (it != ab.rend())
	{
		std::cout << (*it).first << "\t" << it->second << std::endl;
		it++;
	}
	std::cout << "\n---------------------------------------------\n";

	std::cout << "size : " << ab.size() << std::endl;
}

void vector(){
	std::vector<int> p;
	for (int i = 1; i < 15; i++)
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
}

void stack(){
	std::stack<int> q;
	for(int i = 1; i < 15; i++)
		q.push(i);
	
	std::cout << q.top() << std::endl;
	std::cout << q.top() << std::endl;
	for (size_t i = 0; i < q.size(); i++)
		std::cout << q.top() << std::endl;

	std::cout << "###################################\n";
	ft::stack<int> p;

	for (int i = 1; i < 15; i++)
		p.push(i);
	for (size_t i = 0; i < p.size(); i++)
		std::cout << p.top() << std::endl;
}

void set(){
	ft::set<int> s;
	
	s.insert(30);
	s.insert(22);
	s.insert(13);
	s.insert(40);
	s.insert(25);
	s.insert(60);
	s.insert(47);
	s.insert(70);
	s.insert(11);
	s.insert(7);
	s.insert(28);
	s.insert(57);
	s.insert(36);
	s.insert(39);
	s.insert(18);

	ft::set<int>::iterator it = s.begin();
	s.erase(it);
	s.erase(39);
	it = s.begin();

	while (it != s.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << s.size() << std::endl;
	std::cout << "--------------------------------------------\n";
}

int main()
{
	vector();
	map();
	stack();
	set();
}

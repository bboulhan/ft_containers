#include <iostream>
#include <vector>
#include <map>
#include "ft.hpp"
#include "RedBlackTree.hpp"
#include "map.hpp"

void test(){

	ft::map<int, std::string> ab;
	
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
	ab.insert(ft::make_pair(49, "pol"));

	// ft::map<int, std::string> cc;

	ab.erase(ab.begin());
	ab.erase(65);
	ab.erase(45);
	ab.erase(10);
	ab.display();
	std::cout << "size : " << ab.size() << std::endl;
	std::cout << "hey\n";
	// return  ab;
}


int main(){


	// ft::map<int, std::string>::iterator it = ab.begin();
	// ft::map<int, std::string>::iterator ss = ab.end();
	// ft::map<int, std::string>::iterator it = cc.begin();
	// ft::map<int, std::string>::iterator ss;
	// std::cout << &(*it) << "\t" << &(*ss) << "\n";
	// std::cout << &(it) << "\t" << &(ss) << "\n";


	// ab.erase(40);
	// ab.erase(12);

	// cc.insert(ft::pair<int, std::string>(80, "80YY"));
	

	
	// ab.clear();
	
	// it = ab.begin();
	// ab.erase(it, ab.end());

	// ab.tree.Delete(ft::pair<int, std::string>(15, "B15"));
	// ab.tree.Delete(ft::pair<int, std::string>(13, "E13"));

	// ft::map<int, std::string>::iterator ite = ab.end();
	
	// it = ab.begin();
	// while (it != ab.end())
	// {
	// 	std::cout << (*it).first << "\t" << it->second << std::endl;
	// 	it++;
	// }
	test();
	// ss.display();
	std::cout << "\n---------------------------------------------\n";
	// cc.display();

	// std::cout << "size : " << cc.size() << std::endl;
	system("leaks a.out");
	return 0;
}
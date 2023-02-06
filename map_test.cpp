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

	ft::map<int, std::string>::iterator it = ab.begin();
	ft::map<int, std::string>::iterator ite = ab.end();
	while (it != ite)
	{
		std::cout << (*it).first << "\t" << it->second << std::endl;
		it++;
	}
	

	// ab.erase(ab.begin());
	// ab.erase(65);
	// ab.erase(45);
	// ab.erase(10);
	ab.clear();
	ab.display();

	std::cout << "size : " << ab.size() << std::endl;
	// return  ab;
}


int main(){

	ft::map<int, std::string> ab;

	ab.insert(ft::pair<int, std::string>(11, "A11"));
	ab.insert(ft::pair<int, std::string>(15, "B15"));
	ab.insert(ft::pair<int, std::string>(8, "C8"));
	ab.insert(ft::pair<int, std::string>(23, "D23"));
	ab.insert(ft::pair<int, std::string>(13, "E13"));
	ab.insert(ft::pair<int, std::string>(9, "F9"));
	ab.insert(ft::pair<int, std::string>(1, "G1"));
	ab.insert(ft::pair<int, std::string>(10, "H10"));
	ab.insert(ft::pair<int, std::string>(40, "I40"));
	ab.insert(ft::pair<int, std::string>(12, "K12"));
	ab.insert(ft::pair<int, std::string>(50, "J50"));
	ab.insert(ft::pair<int, std::string>(20, "L20"));
	ab.insert(ft::pair<int, std::string>(7, "WE7"));
	ab.insert(ft::pair<int, std::string>(4, "OUB4"));

	ft::map<int, std::string>::iterator it = ab.begin();
	ft::map<int, std::string>::iterator fn = ab.end();
	ft::map<int, std::string> cc(ab);
	cc.insert(ft::pair<int, std::string>(22, "PO22"));
	// cc = ab;


	ft::map<int, std::string>::iterator ss = cc.begin();
	ft::map<int, std::string>::iterator ite = cc.end();
	// cc.insert(ab.begin(), ab.end());
	// cc.insert(std::pair<int, std::string>(80, "80YY"));`
	ab.erase(20);
	ab.erase(40);
	ab.erase(12);

	it = ab.begin();
	ss = cc.begin();
	fn = ab.end()--;

	while (it != ab.end())
	{
		std::cout << (*it).first << "\t" << it->second << std::endl;
		it++;
	}
	// std::cout << "size : " << ab.size() << std::endl;
	std::cout << "\n---------------------------------------------\n";
	
	ite = cc.end();
	// std::cout << "data : " <<cc.tree.get_nil()->parent->data->first << "\n";
	// std::cout << "data : " << it->first << "\n";
	while (ss != ite)
	{
		// std::cout << "hey\n";
		std::cout << (*ss).first << "\t" << ss->second << std::endl;
		// std::cout << "hey 2\n";
		ss++;
		// std::cout << "hey 3\n";

	}

	std::cout << "what\n";
	std::cout << "size : " << cc.size() << std::endl;

	// test();

	// system("leaks a.out");
	return 0;
}

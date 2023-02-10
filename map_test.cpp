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

	ft::map<int, std::string> cc(ab);

	cc[5] = "pol";

	std::cout << ab.size() << "\n";


	// ft::map<int, std::string>::const_iterator it = ab.begin();

	// std::cout << ab.equal_range(10)->first << "\n";
	// std::cout << ab.count(10)->first << "\n";
	// if (cc == ab)
	// 	std::cout << "yess\n";
	// ft::map<int, std::string>::iterator it = ab.begin();
	// ft::map<int, std::string>::iterator ite = ab.end();
	// while (it != ite)
	// {
	// 	std::cout << (*it).first << "\t" << it->second << std::endl;
	// 	it++;
	// }
	

	// ab.erase(ab.begin());
	// ab.erase(65);
	// ab.erase(45);
	// ab.erase(10);
	// ab.clear();
	// ab.display();

	// std::cout << "size : " << ab.size() << std::endl;
	// return  ab;
	// system("leaks a.out");
}


int main(){

	/*ft::map<int, std::string> ab;

	ab.insert(ft::pair<int, std::string>(11, "A11"));
	ab.insert(ft::pair<int, std::string>(15, "B15"));
	ab.insert(ft::pair<int, std::string>(8, "C8"));
	ab.insert(ft::pair<int, std::string>(23, "D23"));
	ab.insert(ft::pair<int, std::string>(13, "E13"));

	ft::map<int, std::string> cc;
	cc.insert(ft::pair<int, std::string>(12, "L20"));
	cc.insert(ft::pair<int, std::string>(7, "WE7"));
	cc.insert(ft::pair<int, std::string>(70, "OUB4"));
	cc.insert(ft::pair<int, std::string>(65, "WQQ65"));
	cc.insert(ft::pair<int, std::string>(45, "UI45"));
	cc.insert(ft::pair<int, std::string>(13, "E13"));

	ab.swap(cc);


	ft::map<int, std::string>::iterator it = ab.begin();
	ft::map<int, std::string>::iterator ss = cc.begin();


	it = ab.begin();

	while (it != ab.end())
	{
		std::cout << (*it).first << "\t" << it->second << std::endl;
		it++;
	}
	// ab.display();
	std::cout << "size : " << ab.size() << std::endl;
	std::cout << "\n---------------------------------------------\n";
	
	ss = cc.begin();

	while (ss != cc.end())
	{
		std::cout << (*ss).first << "\t" << ss->second << std::endl;
		ss++;
	}
	// cc.display();
	std::cout << "size : " << cc.size() << std::endl;*/

	test();

	// system("leaks a.out");
	return 0;
}

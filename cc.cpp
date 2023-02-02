#include <iostream>
#include <cmath>
#include <vector>
#include <map>


int main()
{
	std::map<int, std::string> ab;

	ab.insert(std::pair<int, std::string>(11, "A11"));
	ab.insert(std::pair<int, std::string>(15, "B15"));
	ab.insert(std::pair<int, std::string>(8, "C8"));
	ab.insert(std::pair<int, std::string>(23, "D23"));
	ab.insert(std::pair<int, std::string>(13, "E13"));
	ab.insert(std::pair<int, std::string>(9, "F9"));
	ab.insert(std::pair<int, std::string>(1, "G1"));
	ab.insert(std::pair<int, std::string>(10, "H10"));
	ab.insert(std::pair<int, std::string>(40, "I40"));
	ab.insert(std::pair<int, std::string>(12, "K12"));
	ab.insert(std::pair<int, std::string>(50, "J50"));
	ab.insert(std::pair<int, std::string>(20, "L20"));
	ab.insert(std::pair<int, std::string>(7, "WE7"));
	ab.insert(std::pair<int, std::string>(4, "OUB4"));

	std::map<int, std::string>::iterator it = ab.begin();
	std::map<int, std::string>::iterator ss;

	// std::pair<std::map<int, std::string>::iterator, bool> pp;
	// pp = ab.insert(std::pair<int, std::string>(22, "PO22"));
	// std::map<int, std::string> cc;
	// cc.insert(std::pair<int, std::string>(22, "PO22"));
	// cc.insert(ab.begin(), ab.end());
	// cc.insert(std::pair<int, std::string>(80, "80YY"));


	ab.erase(ab.begin(), ab.end());


	// it = ab.begin();

	// while (it != ab.end())
	// {
	// 	std::cout << (*it).first << "\t" << it->second << std::endl;
	// 	it++;
	// }
	std::cout << "\n---------------------------------------------\n";


	

	std::cout << "size : " << ab.size() << std::endl;

	return 0;
}
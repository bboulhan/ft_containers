#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#define ft std

// std::multiplies<int>
// std::greater<int>

int main()
{
	std::map<int, std::string, std::multiplies<int> > ab;

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

	std::map<int, std::string>::iterator it = ab.begin();
	// std::map<int, std::string>::const_iterator it = ab.begin();
	// std::map<int, std::string>::const_iterator ite = ab.end();

	// std::cout << ab.end()->first << "\n";
	// std::cout << ab.end()->first << "\n";

	// std::map<int, std::string> cc;
	// // cc.insert(std::pair<int, std::string>(22, "PO22"));
	// ab = cc;

	// std::map<int, std::string>::iterator ss = cc.begin();

	// cc.insert(ab.begin(), ab.end());
	// cc.insert(std::pair<int, std::string>(80, "80YY"));

	// ab.erase(20);
	// ab.erase(40);
	// ab.erase(12);

	// it = ab.begin();
	// ss = cc.begin();
	while (it != ab.end())
	{
		std::cout << (*it).first << "\t" << it->second << std::endl;
		it++;
	}
	std::cout << "size : " << ab.size() << std::endl;
	std::cout << "\n---------------------------------------------\n";



	

	// std::cout << "size : " << cc.size() << std::endl;

	return 0;
}

#include <iostream>
#include "ft.hpp"
#include "vector.hpp"
#include <vector>
#include <set>

int main()
{
	std::set<int> set;

	set.insert(30);
	set.insert(22);
	set.insert(13);
	set.insert(40);
	set.insert(25);
	set.insert(60);
	set.insert(47);
	set.insert(70);
	set.insert(11);
	set.insert(7);
	set.insert(28);
	set.insert(57);
	set.insert(36);
	set.insert(39);
	set.insert(18);

	std::set<int>::iterator it = set.begin();
	std::set<int>::iterator ss;

	it++;it++;
	set.erase(it);
	set.erase(39);

	// std::cout << *(set.find(28)) << std::endl;
	// std::cout << *(set.lower_bound(28)) << std::endl;
	// std::cout << *(set.upper_bound(28)) << std::endl;



	it = set.begin();
	// set.clear();
	set.erase(it, set.end());

	// it = set.begin();

	// while (it != set.end())
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
	std::cout << "--------------------------------------------\n";
	std::cout << set.size() << std::endl;
	// system("leaks a.out");

}
#include <iostream>
#include <vector>
#include <map>
#include "ft.hpp"
#include "RedBlackTree.hpp"
#include "map.hpp"







int main(){

	ft::map<int, std::string> cc;
	
	cc.tree.insert(ft::pair<int, std::string>(11, "A11"));
	cc.tree.insert(ft::pair<int, std::string>(15, "B15"));
	cc.tree.insert(ft::pair<int, std::string>(8, "C8"));
	cc.tree.insert(ft::pair<int, std::string>(23, "D23"));
	cc.tree.insert(ft::pair<int, std::string>(13, "E13"));
	cc.tree.insert(ft::pair<int, std::string>(9, "F9"));
	cc.tree.insert(ft::pair<int, std::string>(1, "G1"));
	cc.tree.insert(ft::pair<int, std::string>(10, "H10"));
	cc.tree.insert(ft::pair<int, std::string>(40, "I40"));
	cc.tree.insert(ft::pair<int, std::string>(12, "K12"));
	cc.tree.insert(ft::pair<int, std::string>(50, "J50"));
	cc.tree.insert(ft::pair<int, std::string>(20, "L20"));
	// cc.tree.insert(ft::pair<int, std::string>(7, "WE7"));
	// cc.tree.insert(ft::pair<int, std::string>(4, "OUB4"));
	
	ft::map<int, std::string>::iterator it = cc.begin();

	std::cout << it->first << " " << it->second << std::endl;

	it++;

	std::cout << it->first << " " << it->second << std::endl;
	// ft::map<int, std::string> ab(cc);
	// ++it;
	std::cout << it->first << " " << it->second << std::endl;
	
	
	ft::map<int, std::string> ab;
	
	ab = cc;
	// ab.tree.insert(ft::pair<int, std::string>(11, "A11"));
	// ab.tree.insert(ft::pair<int, std::string>(15, "B15"));

	// cc.tree.Delete(ft::pair<int, std::string>(15, "B15"));
	// cc.tree.Delete(ft::pair<int, std::string>(13, "E13"));


	// cc.tree.display(cc.tree.root, 0);

	// cc.tree.display_data(cc.tree.first_elem());
	// cc.tree.display_data(cc.tree.last_elem());

	cc.tree.all_elem(cc.tree.first_elem(), cc.tree.last_elem());


	std::cout << "\n---------------------------------------------\n";


	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include "ft.hpp"
#include "RedBlackTree.hpp"
#include "map.hpp"


void test(){

	ft::map<int, std::string> ft_map;
	
	ft_map.tree.insert(ft::pair<int, std::string>(11, "A11"));
	ft_map.tree.insert(ft::pair<int, std::string>(15, "B15"));
	ft_map.tree.insert(ft::pair<int, std::string>(8, "C8"));
	ft_map.tree.insert(ft::pair<int, std::string>(23, "D23"));
	ft_map.tree.insert(ft::pair<int, std::string>(13, "E13"));
	ft_map.tree.insert(ft::pair<int, std::string>(9, "F9"));
	ft_map.tree.insert(ft::pair<int, std::string>(1, "G1"));
	ft_map.tree.insert(ft::pair<int, std::string>(10, "H10"));
	ft_map.tree.insert(ft::pair<int, std::string>(40, "I40"));
	ft_map.tree.insert(ft::pair<int, std::string>(12, "K12"));
	ft_map.tree.insert(ft::pair<int, std::string>(50, "J50"));
	ft_map.tree.insert(ft::pair<int, std::string>(20, "L20"));

	ft_map.tree.display(ft_map.tree.root, 0);
	std::cout << "\n---------------------------------------------\n";
}



int main(){

	std::map<int , int> ab;
	ab.insert(std::pair<int,int>(45, 22));
	ab.insert(std::pair<int,int>(11, 10));
	ab.insert(std::pair<int,int>(11, 10));
	ab.insert(std::pair<int,int>(16, 20));
	ab.insert(std::pair<int,int>(18, 230));

	std::map<int, int> pp(ab);


	ab.erase(11);
	ab.erase(18);

	std::map<int, int>::iterator it = ab.begin();
	std::map<int, int>::iterator ita = pp.begin();
	
	while (it != ab.end()){
		std::cout << (*it).first << "\t" << (*it).second << "\n";
		it++;
	}
	std::cout << "\n---------------------------------------------\n";

	while (ita != pp.end()){
		std::cout << (*ita).first << "\t" << (*ita).second << "\n";
		ita++;

	}












	// ft::map<int, std::string> ab(ft_map);


	// ft_map.tree.Delete(ft::pair<int, std::string>(15, "B15"));
	// ft_map.tree.Delete(ft::pair<int, std::string>(13, "E13"));
	

	// ab.tree.Delete(ft::pair<int, std::string>(15, "B15"));
	// ab.tree.Delete(ft::pair<int, std::string>(13, "E13"));
	
	


	// ab.tree.display(ab.tree.root, 0);
	// tree.Delete(40);
	// tree.Delete(8);
	// tree.Delete(15);
	// tree.Delete(13);
	// tree.Delete(5);
	// tree.Delete(11);



	// tree.right_rotation(tree.root);
	
	// print_the_tree(tree.min(tree.search(72)));
	// print2D(tree.root);
	// print_the_tree(tree.search(55));
	// tree.left_rotation(tree.get_root()->right->left);

	// print2D(tree.root);
	// std::cout << "\n---------------------------------------------\n";
	// print_the_tree(tree.get_root()->right->left);
	




	return 0;
}
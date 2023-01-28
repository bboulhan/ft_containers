#include <iostream>
#include <vector>
#include <map>
#include "ft.hpp"
#include "RedBlackTree.hpp"
#include "map.hpp"


int main(){



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


	

	// tree.insert(11, ibra);
	// tree.insert(11, "11");
	// tree.insert(15);
	// tree.insert(8);
	// tree.insert(23);
	// tree.insert(13);
	// tree.insert(9);
	// tree.insert(1);
	// tree.insert(10);
	// tree.insert(40);
	// tree.insert(60);
	// tree.insert(66);
	// tree.insert(7);
	// tree.insert(5);
	// tree.insert(12);






	std::cout << "\n";
	

	// std::cout << ft_map.tree.root->right->data.first << std::endl;
	// std::cout << ft_map.tree.root->left->data.second << std::endl;
	ft_map.tree.display(ft_map.tree.root, 0);
	
	std::cout << "\n---------------------------------------------\n";

	// tree.Delete(40);
	// tree.Delete(8);
	// tree.Delete(15);
	// tree.Delete(13);
	// tree.Delete(5);
	// tree.Delete(11);



	// tree.right_rotation(tree.root);
	// std::cout << "\n---------------------------------------------\n";
	
	// print_the_tree(tree.min(tree.search(72)));
	// print2D(tree.root);
	// print_the_tree(tree.search(55));
	// tree.left_rotation(tree.get_root()->right->left);

	// print2D(tree.root);
	// std::cout << "\n---------------------------------------------\n";
	// print_the_tree(tree.get_root()->right->left);
	// system("leaks a.out");




	return 0;
}
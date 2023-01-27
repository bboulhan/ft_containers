#include <iostream>
#include <vector>
#define COUNT 10
#include <map>
#include "ft.hpp"
#include "RedBlackTree.hpp"


int main(){

	RedBlackTree tree;
	

	tree.insert(11);
	tree.insert(15);
	tree.insert(8);
	tree.insert(23);
	tree.insert(13);
	tree.insert(9);
	tree.insert(1);
	tree.insert(10);
	tree.insert(40);
	tree.insert(60);
	tree.insert(66);
	tree.insert(7);
	tree.insert(5);
	tree.insert(12);






	std::cout << "\n";
	print2D(tree.root);


	
	std::cout << "\n---------------------------------------------\n";

	tree.Delete(40);
	tree.Delete(8);
	tree.Delete(15);
	tree.Delete(13);
	tree.Delete(5);
	tree.Delete(11);



	// tree.right_rotation(tree.root);
	std::cout << "\n---------------------------------------------\n";
	
	// print_the_tree(tree.min(tree.search(72)));
	print2D(tree.root);
	// print_the_tree(tree.search(55));
	// tree.left_rotation(tree.get_root()->right->left);

	// print2D(tree.root);
	// std::cout << "\n---------------------------------------------\n";
	// print_the_tree(tree.get_root()->right->left);
	// system("leaks a.out");




	return 0;
}
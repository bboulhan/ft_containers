#include <iostream>
#include <vector>
#define COUNT 10
#include <map>
#include "ft.hpp"
#include "RedBlackTree.hpp"


int main(){

	RedBlackTree tree(50);
	
	// for(int i = 1; i <= 50; i++){
	// 	tree.insert(i);
	// 	tree.insert(100 - i);

	// }
	tree.insert(40);
	tree.insert(30);
	tree.insert(60);
	tree.insert(70);
	tree.insert(55);
	tree.insert(58);
	tree.insert(53);
	tree.insert(80);
	tree.insert(51);
	tree.insert(72);
	tree.insert(25);
	tree.insert(22);
	tree.insert(54);
	tree.insert(50);





	std::cout << "\n";
	print2D(tree.root);

	// tree.right_rotation(tree.root);
	// std::cout << "\n---------------------------------------------\n";
	
	// print2D(tree.root);
	// print_the_tree(tree.root);
	// tree.left_rotation(tree.get_root()->right->left);

	// print2D(tree.root);
	// std::cout << "\n---------------------------------------------\n";
	// print_the_tree(tree.get_root()->right->left);
	// system("leaks a.out");




	return 0;
}
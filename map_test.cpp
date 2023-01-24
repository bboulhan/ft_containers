#include <iostream>
#include <vector>
#define COUNT 10
#include <map>
#include "ft.hpp"
#include "RedBlackTree.hpp"

using namespace std;
void print2DUtil(node *root , int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    cerr << root->data << endl;
    // Process left child
    print2DUtil(root->left, space);
}

void print2D(node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}



int main(){

	RedBlackTree tree(50);
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

	print2D(tree.root);
	tree.right_rotation(tree.get_root()->right);
	tree.right_rotation(tree.get_root()->right);

	std::cout << "\n---------------------------------------------\n";
	print2D(tree.root);
	print_the_tree(tree.get_root()->right);
	print_the_tree(tree.get_root()->right->left);





	return 0;
}
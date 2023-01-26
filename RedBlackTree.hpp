/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:45:51 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/26 22:46:01 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include <iostream>
# define black 0
# define red 1

// 	COLOR 1 == RED | COLOR 0 = BLACK //

struct node{
	int data;
	int color;
	// info *token;
	node *parent;
	node *right;
	node *left;
	node(int value) : data(value){
		color = red;
		// token = NULL;
		right = NULL;
		left = NULL;
		parent = NULL;
	}
};


void print2DUtil(node *root , int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    std::cout << "\n";
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    if (root->color == 1)
		std::cerr << "\033[1;31m"<< root->data << "\033[0m\n";
	else
		std::cerr << "\033[1;34m"<< root->data << "\033[0m\n";
    print2DUtil(root->left, space);
}

void print2D(node *root)
{
   print2DUtil(root, 0);
}

struct info{
	node *parent;
	node *grand_parent;
	node *uncle;
	info(){
		parent = NULL;
		grand_parent = NULL;
		uncle = NULL;
	}
};

class RedBlackTree{
	node *Nil;
	public:
		node *root;
		friend void print2D(node *root);
		RedBlackTree(){
			root = NULL;
			Nil = NULL;
		};
		RedBlackTree(int data){
			root = new node(data);
			root->color = black;
		}
		node *get_root(){return root;}
		
		void insert(int data){
			node *parent = where(data);
			if (parent == NULL){
				root = new node(data);
				root->color = black;
				return;
			}
			node *child = new node(data);
			child->parent = parent;
			if (data > parent->data)
				parent->right = child;
			else
				parent->left = child;
			check_violation(child);
			
		}
		
		void check_violation(node *gay)
		{
			if (root == gay && gay->color == red){
				gay->color = black;
				return;
			}
			if (gay->parent->color == black)
				return ;
			
			node *uncle = NULL;
			node *grand_pa = NULL;
			node *original_parent = gay->parent;
			
			if (gay->parent->parent)
				grand_pa = gay->parent->parent;
			if (grand_pa){
				if (gay->parent->data < grand_pa->data && grand_pa->right)
					uncle = grand_pa->right;
				else if (gay->parent->data > grand_pa->data && grand_pa->left)
					uncle = grand_pa->left;
			}

			if (uncle && uncle->color == red){
				uncle->color = black;
				gay->parent->color = black;
				grand_pa->color = red;
			// std::cout << "the grandPA data : " << grand_pa->data << "\n";
				check_violation(grand_pa);
			}
			else{
				// triangle case //
				if (gay->parent->right && gay->parent->data < grand_pa->data && gay->parent->right == gay){
					left_rotation(gay->parent);
					check_violation(original_parent);
				}
				else if (gay->parent->left && gay->parent->data > grand_pa->data && gay->parent->left == gay){
					right_rotation(gay->parent);
					// print2D(root);
					// std::cout << "gay data : " << gay->data << "\n";
					// std::cout << "gay parent data : " << original_parent->data << "\n";
					
					check_violation(original_parent);
				}
				// line case //
				else{
					if (gay->parent->data < grand_pa->data && gay->parent->left && gay->parent->left == gay){
						
						right_rotation(grand_pa);
					}
					else
						left_rotation(grand_pa);
					grand_pa->color = (grand_pa->color + 1) % 2;
					gay->parent->color = (gay->parent->color + 1) % 2;
					check_violation(grand_pa);
				}
				// std::cout << "hey\n";
			}
		}

		void right_rotation(node *tree){
			node *tmp = NULL;
			node *parent = NULL;
			node *child_L = NULL;
			
			if (!tree->left)
				return ;
				
			tmp = tree;	
			parent = tree->parent;
			child_L = tree->left;
			
			if (parent && tmp->data < parent->data)
				parent->left = child_L;
			else if (parent)
				parent->right = child_L;
			
			// std::cout << "here\n";
			if (child_L->right){
				tmp->left = child_L->right;
				child_L->right->parent = tmp;
			}
			else
				tmp->left = NULL;
			
			child_L->parent = parent;
			tmp->parent = child_L;
			child_L->right = tmp;
			if (root == tmp)
				root = child_L;
		}

		void left_rotation(node *tree){
			node *tmp = NULL;
			node *parent = NULL;
			node *child_R = NULL;

			if (!tree->right)
				return ;
			tmp = tree;
			parent = tree->parent;
			child_R = tree->right;


			if (parent && tmp->data < parent->data)	
				parent->left = child_R;
			else if (parent)
				parent->right = child_R;
			
			if (child_R->left){
				tmp->right = child_R->left;
				child_R->left->parent = tmp;
			}
			else
				tmp->right = NULL;
			
			child_R->parent = parent;
			tmp->parent = child_R;
			child_R->left = tmp;
			
			if (root == tmp)
				root = child_R;
		}

		
		node *where(int data){
			node *tmp = root;
			node *tmp2 = tmp;
			while (tmp){
				tmp2 = tmp;
				if (data > tmp->data)
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			return tmp2;
		}

		void replace(node *del, node *tree){
			if (!del->parent)
				this->root = tree;
			else if (del->parent->left == del)
				del->parent->left = tree;
			else
				del->parent->right = tree;
			if (tree)
				tree->parent = del->parent;
		}

		node *search(int data){
			node *tmp = root;
			while (tmp && tmp->data != data){
				if (tmp->data < data)
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			return tmp;
		}

		node *max(node *del){
			node *tmp = del;
			node *max = tmp;
			
			if (tmp->right)
				tmp = tmp->right;
			while (tmp){
				max = tmp;
				if (tmp->left)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return max;
		}

		node *min(node *del){
			node *tmp = del;
			node *min;
			
			if (tmp->left)
				tmp = tmp->left;
			min = tmp;
			while(tmp){
				min = tmp;
				if (tmp->right)
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			return min;
		}

		void Delete(int data){
			node *del = search(data);
			node *sibling = NULL;
			node *original_parent = NULL;
			int original_color = 3;

			if (!del->left && !del->right)
				replace(del, NULL);
			else if (!del->left){
				del->right->color = black;
				replace(del, del->right);
			}
			else if (!del->right){
				del->left->color = black;
				replace(del, del->left);
			}
			else{				
				node *tmp = min(del);
				original_color = tmp->color;
				if (del->parent){
					if (tmp->parent->right == tmp)
						sibling = tmp->parent->left;
					else
						sibling = tmp->parent->right;
				}
				if (tmp->parent)
					original_parent = tmp->parent;
				replace(tmp, NULL);
				tmp->left = del->left;
				tmp->right = del->right;
				if (del->left)
					del->left->parent = tmp;
				if (del->right)
					del->right->parent = tmp;
				replace(del, tmp);
			}
			print2D(root);

			// std::cout << "sibling data : " << sibling->data << "\n"; 
			// std::cout << "sibling parent data : " << sibling->parent->data << "\n"; 
			// std::cout << "original_parent data : " << original_parent->data << "\n";
			// std::cout << "original parent parent data : " << original_parent->parent->data << "\n";
			// if (original_parent->right)
			// 	std::cout << "original parent right : " << original_parent->right->data << "\n";
			// if (original_parent->left)
			// 	std::cout << "original parent left : " << original_parent->left->data << "\n";
			
			
			if (sibling && original_color == black){
				node *tmp = new node(0);
				if (sibling->color == red){
					sibling->color = black;
					sibling->parent->color = red;
					if (sibling->parent->right == sibling){
						sibling->parent->left = tmp;
						tmp->parent = sibling->parent;
						left_rotation(tmp->parent);
						sibling = tmp->parent->right;
					}
					else{
						sibling->parent->right = tmp;
						tmp->parent = sibling->parent;
						right_rotation(tmp->parent);
						sibling = original_parent->left;
					}
				}
				else if (sibling->color == black){
					if ((sibling->right && sibling->right->color == black) || !sibling->right){
						if ((sibling->left && sibling->left->color == black) || !sibling->left){
							sibling->color = red;
						}
					}
				}


				
				clean(tmp);						
			}
			// else if (sibling) {
			// 	sibling->parent->color = black;
			// }
		
			
			
		
			delete del;
		}
		
		void clean(node *trash){
			if (trash->parent->right == trash)
				trash->parent->right = NULL;
			else
				trash->parent->left = NULL;
			delete trash;
		}
		
		
	friend void print_the_tree(node *tree);
};






	void print_the_tree(node *tree){
		if (!tree)
			return;
		std::cout << "data: " << tree->data << "\tcolor: " << tree->color << std::endl;
		if (tree->parent)
			std::cout << "parent data: " << tree->parent->data << "\tparent color: " << tree->parent->color << std::endl;
		if (tree->left)
			std::cout << "left data: " << tree->left->data << "\tleft color: " << tree->left->color << std::endl;
		if (tree->right)
			std::cout << "right data: " << tree->right->data << "\tright color: " << tree->right->color << std::endl;
	}



#endif
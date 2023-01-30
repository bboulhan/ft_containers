/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:45:51 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/30 21:57:35 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP


#include <iostream>
#include "ft.hpp"
#include <unistd.h>
# define black 0
# define red 1
#define COUNT 10
// 	COLOR 1 == RED | COLOR 0 = BLACK //


template<class T>
struct node{
	T data;
	int color;
	node *parent;
	node *right;
	node *left;
	node(T value){
		data = value;
		color = red;
		right = NULL;
		left = NULL;
		parent = NULL;
	}
	node() : color(black), right(NULL), left(NULL), parent(NULL) {
	}
};

// template <class T>
// void print2DUtil(node<T> *root , int space)
// {
//     if (root == NULL)
//         return;
//     space += COUNT;
//     print2DUtil(root->right, space);
//     std::cout << "\n";
//     for (int i = COUNT; i < space; i++)
//         std::cout << " ";
//     if (root->color == 1)
// 		std::cerr << "\033[1;31m"<< root->data << "\033[0m\n";
// 	else
// 		std::cerr << "\033[1;34m"<< root->data << "\033[0m\n";
//     print2DUtil(root->left, space);
// }

// template <class T>
// void print2D(node<T> *root)
// {
//    print2DUtil(root, 0);
// }


template <class T, class Compare, class Alloc>
class RedBlackTree{
	public:
		typedef node<T> node;
        typedef Compare value_compare;
        // typedef Key key_type;
        typedef T value_type;
	
		node *root;
		std::allocator <node> alloc;
	// private:
	
	public:

	
		void display(node *root, int space){		
			if (root == NULL)
				return;
			// std::cout << root->data.first << std::endl;
			space += COUNT;
			display(root->right, space);
			std::cout << "\n";
			for (int i = COUNT; i < space; i++)
				std::cout << " ";
			usleep(1000);
			if (root->color == red)
				std::cerr << "\033[1;31m"<< root->data.first << " " << root->data.second << "\033[0m\n";
			else
				std::cerr << "\033[1;34m"<< root->data.first << " " << root->data.second << "\033[0m\n";
			display(root->left, space);
		}

		void display_data(node *tree){
			if (tree == NULL)
				return;
			std::cout << "first : " <<tree->data.first << "\tsecond : " << tree->data.second << std::endl;
			if (tree->parent)
				std::cout << "parent first : " <<tree->parent->data.first << "\tparent second : " << tree->parent->data.second << std::endl;
			if (tree->left)
				std::cout << "left first : " <<tree->left->data.first << "\tleft second : " << tree->left->data.second << std::endl;
			if (tree->right)
				std::cout << "right first : " <<tree->right->data.first << "\tright second : " << tree->right->data.second << std::endl;
		}

		RedBlackTree(){
			root = NULL;
		};

		RedBlackTree &operator=(const RedBlackTree &op){
			root = op.root;
			return *this;
		};

		RedBlackTree(const RedBlackTree &copy){
			memcpy(this, &copy, sizeof(RedBlackTree));
		};
		
		RedBlackTree(T data){
			root = alloc.allocate(1);
			alloc.construct(root->data, data);
			root->color = black;
		}

		~RedBlackTree(){
			deleter(root);	
		}
		
		void deleter(node *tree){
			if (tree == NULL)
				return;
			deleter(tree->left);
			deleter(tree->right);
			delete tree;
		}

		node *get_root(){return root;}
		
		void insert(T data){
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
					check_violation(original_parent);
				}
				// line case //
				else{
					if (gay->parent->data < grand_pa->data && gay->parent->left && gay->parent->left == gay)
						right_rotation(grand_pa);
					else
						left_rotation(grand_pa);
					grand_pa->color = (grand_pa->color + 1) % 2;
					gay->parent->color = (gay->parent->color + 1) % 2;
					check_violation(grand_pa);
				}
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

		
		node *where(T data){
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

		node *search(T data){
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
			max = tmp;
			while (tmp){
				max = tmp;
				tmp = tmp->left;
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
				tmp = tmp->right;
			}
			return min;
		}

		void Delete(T data){
			node *del = search(data);
			node *tmp = min(del);
			int original_color = 3;
			bool fake_node = false;

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
				node *child = tmp->left;
				if (!child){
					child = new node();
					child->parent = tmp;
					tmp->left = child;
					fake_node = true;
				}
				
				original_color = tmp->color;
				replace(tmp, child);
				tmp->left = del->left;
				tmp->right = del->right;
				if (del->left)
					del->left->parent = tmp;
				if (del->right)
					del->right->parent = tmp;
				replace(del, tmp);
				if (original_color == black)
					del_fix(child);
				else
					tmp->color = black;
				if (fake_node == true)
					clean(child);
			}

			delete del;
		}
		
		void del_fix(node *fix){
			node *tmp = NULL;
			node *sibling = NULL;
			
			while (fix->color == black && fix != root){

				if (fix->parent->right == fix)
					sibling = fix->parent->left;
				else
					sibling = fix->parent->right;

				if(sibling && sibling->color == red){
					sibling->color = black;
					sibling->parent->color = red;
					left_rotation(fix->parent);
					sibling = fix->parent->right;
				}
				else if (special_case(sibling, fix) == true)
					fix = fix->parent;
				else if (sibling && sibling->color == black){
					if (((sibling->left && sibling->left == black) || !sibling->left) && ((sibling->right && sibling->right == black) || !sibling->right)){
						if (sibling->left)
							sibling->left->color = black;
						sibling->color = red;
						right_rotation(sibling);
						sibling = fix->parent->right;
					}
					else if (sibling->right && sibling->right->color == red){
						sibling->color = red;
						fix->parent->color = black;
						sibling->right->color = black;
						// print2D(root);
						left_rotation(fix->parent);
						fix = root;
					}
					else if (sibling->left && sibling->left->color == red){
						sibling->color = red;
						sibling->left->color = black;
						right_rotation(sibling);
					}
				}
			}
			fix->color = black;
		}
 
		bool special_case(node *sibling, node *fix){
			if ((sibling && sibling->color == black) || !sibling)
			{
				if ((sibling->right && sibling->right->color == black) || !sibling->right)
				{
						if ((sibling->left && sibling->left->color == black) || !sibling->left){
							if (sibling)
								sibling->color = red;
							return true;
						}
				}
			}
			return false;
		}
		
		void clean(node *trash){
			if (trash->parent->right == trash)
				trash->parent->right = NULL;
			else
				trash->parent->left = NULL;
			delete trash;
		}
		
		
};








#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:45:51 by bboulhan          #+#    #+#             */
/*   Updated: 2023/01/24 21:45:59 by bboulhan         ###   ########.fr       */
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
			
			
		}
		
		// node *check_violation(node *gay){
		// 	if (gay->parent->color == black)
		// 		return NULL;
		// 	node *grand_parent = gay->parent->parent;
		// 	node *uncle;
		// 	if (gay->parent->data < grand_parent->data)
		// 		uncle = grand_parent->right;
		// 	else
		// 		uncle = grand_parent->left;
		// 	if (uncle->color == red)
			
			
		// }

		void right_rotation(node *tree){
			node *tmp;
			node *parent;
			node *child_L;
			
			tmp = tree;
			parent = tree->parent;
			child_L = tree->left;

			if (tmp->data < parent->data)
				parent->left = child_L;
			else
				parent->right = child_L;
			
			// if (child_L->right){
				tmp->left = child_L->right;
				child_L->right->parent = tmp;
			// }
			
			child_L->parent = parent;
			tmp->parent = child_L;
			child_L->right = tmp;

			
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
		
		
	friend void print_the_tree(node tree);
};





	void print_the_tree(node *tree){
		std::cout << "data: " << tree->data << "\tcolor: " << tree->color << std::endl;
		if (tree->parent)
			std::cout << "parent data: " << tree->parent->data << "\tparent color: " << tree->parent->color << std::endl;
		if (tree->left)
			std::cout << "left data: " << tree->left->data << "\tleft color: " << tree->left->color << std::endl;
		if (tree->right)
			std::cout << "right data: " << tree->right->data << "\tright color: " << tree->right->color << std::endl;
	}



#endif
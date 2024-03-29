/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:45:51 by bboulhan          #+#    #+#             */
/*   Updated: 2023/02/19 15:00:35 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP


#include <iostream>
#include "ft.hpp"
#include "map_iterators.hpp"
#include <unistd.h>

# define black 0
# define red 1
// 	COLOR 1 == RED | COLOR 0 = BLACK //



namespace ft{

template<class T> 
struct node{
	std::allocator<T> alloc;
	T *data;
	bool nil;
	int color;
	node *parent;
	node *right;
	node *left;
	node(T value){
		data = alloc.allocate(1);
		alloc.construct(data, value);
		color = red;
		right = NULL;
		left = NULL;
		parent = NULL;
		nil = false;
	}
	node() : color(black), parent(NULL), right(NULL) , left(NULL) {
		data = alloc.allocate(1);
		nil = true;
	}
	void clear(){
		if (this->data){
			alloc.deallocate(data, 1);
			data = NULL;
		}
	}

	~node(){}
};

template <class T, class Compare, class Alloc>
class RedBlackTree{
	public:
		typedef node<T> node;
        typedef Compare value_compare;
        typedef T value_type;
		typedef typename Alloc::size_type size_type;
		typedef typename ft::map_iterator<value_type, node > 		iterator;
		typedef typename 	Alloc:: template rebind<node>::other 	allocator;
	
	private:
		allocator alloc;
		Compare comp;
		node *root;
		node *nil;
		size_type _size;
	public:
	

	/************************************************ display ************************************************/
	
		/*void display_set(node *root, int space){		
			if (root == NULL || root == nil)
				return;
			space += COUNT;
			display_set(root->right, space);
			std::cout << "\n";
			for (int i = COUNT; i < space; i++)
				std::cout << " ";
			if (root->color == red)
				std::cerr << "\033[1;31m"<< *root->data << "\033[0m\n";
			else
				std::cerr << "\033[1;34m"<< *root->data << "\033[0m\n";
			display_set(root->left, space);
		}
	
		void display_map(node *root, int space)const{		
			if (root == NULL || root == nil)
				return;
			space += COUNT;
			display_map(root->right, space);
			std::cout << "\n";
			for (int i = COUNT; i < space; i++)
				std::cout << " ";
			if (root->color == red)
				std::cerr << "\033[1;31m"<< root->data->first << " " << root->data->second << "\033[0m\n";
			else
				std::cerr << "\033[1;34m"<< root->data->first << " " << root->data->second << "\033[0m\n";
			display_map(root->left, space);
		}

		void display_data(node *tree){
			if (tree == NULL)
				return;
			std::cout << tree->data << "\n";
			if (tree->parent)
				std::cout << "parent first : " <<tree->parent->data->first << "\tparent second : " << tree->parent->data->second << std::endl;
			if (tree->left)
				std::cout << "left first : " <<tree->left->data->first << "\tleft second : " << tree->left->data->second << std::endl;
			if (tree->right)
				std::cout << "right first : " <<tree->right->data->first << "\tright second : " << tree->right->data->second << std::endl;
			if (tree->data)
				std::cout << "first : " <<tree->data->first << "\tsecond : " << tree->data->second << std::endl;
		}*/

	/****************************************** Constructors *****************************************/

		RedBlackTree(Compare comp = Compare(), allocator alloc = allocator()) : alloc(alloc), comp(comp){
			root = NULL;
			nil = alloc.allocate(1);
			alloc.construct(nil, node());
			_size = 0;
		};

		RedBlackTree &operator=(const RedBlackTree &op){
			
			if (first_elem())
				first_elem()->left = NULL;
			if (nil)
				clean(nil);
			this->destroy(root);
			alloc = op.alloc;
			root = NULL;
			nil = alloc.allocate(1);
			alloc.construct(nil, node());
			if (op.size() == 0)
				return *this;
			ft::RedBlackTree<T, Compare, Alloc>::iterator it(op.first_elem());
			ft::RedBlackTree<T, Compare, Alloc>::iterator ite(op.last_elem());
			while (it != ite){
				this->insert(*it);
				it++;
			}
			return *this;
		};
		
		RedBlackTree(const RedBlackTree &copy) : comp(copy.comp){
			node *first = copy.first_elem();
			node *last = copy.last_elem();
			alloc = copy.alloc;
			_size = 0;
			root = NULL;
			nil = alloc.allocate(1);
			alloc.construct(nil, node());
			while (first != last){
				this->insert(*first->data);
				first = next(first);
			}
		};
		
		RedBlackTree(T data) : comp(Compare()), alloc(allocator()){
			root = alloc.allocate(1);
			alloc.construct(root, node(data));
			root->color = black;
			nil = alloc.allocate(1);
			alloc.construct(nil, node());
			nil->parent = root;
			root->right = nil;
			root->left = nil;
			nil->left = NULL;
			_size = 1;
		}

	/******************************************** desctructor **********************************************/
		void destroy(node *tree)
		{
			if (tree)
			{
				destroy(tree->right);
				destroy(tree->left);
				tree->clear();
				alloc.deallocate(tree, 1);
				tree = NULL;
			}
			_size = 0;	
		}

		~RedBlackTree(){
			if (first_elem())
				first_elem()->left = NULL;
			if (this->nil != NULL)
				clean(nil);
			destroy(root);
		}

		void cleaner(node *tree){
			if (!tree || tree == nil)
				return;
			cleaner(tree->right);
			cleaner(tree->left);
			clean(tree);
		}
		
		void deleter(){
			if (!root)
				return;
			nil->right = NULL;
			first_elem()->left = NULL;
			cleaner(root);
			nil->parent = NULL;
			_size = 0;
			root = NULL;
		}

		void clean(node *trash){
			if (!trash)
				return;
			if (trash->parent && trash->parent->right == trash)
				trash->parent->right = NULL;
			else if (trash->parent)
				trash->parent->left = NULL;
			trash->clear();

			alloc.destroy(trash);
			alloc.deallocate(trash, 1);
			trash = NULL;
		}
		
		/******************************************* modifiers ****************************************************/
		
		node *insert(T data){
			node *parent = where(data);
			if (parent == NULL){
				root = alloc.allocate(1);
				alloc.construct(root, node(data));
				root->color = black;
				this->_size++;
				nil->parent = root;
				root->right = nil;
				root->left = nil;
				nil->right = root;
				return root;
			}
			nil->parent->right = NULL;
			first_elem()->left = NULL;
			node *child = alloc.allocate(1);
			alloc.construct(child, node(data));
			child->parent = parent;
			if (!comp(data, *parent->data))
				parent->right = child;
			else
				parent->left = child;
			this->_size++;
			check_violation(child);
			nil->parent = last_elem();
			nil->parent->right = nil;
			first_elem()->left = nil;
			nil->right = first_elem();
			return child;
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
				if (grand_pa->left == gay->parent && grand_pa->right)
					uncle = grand_pa->right;
				else if (grand_pa->right == gay->parent && grand_pa->left)
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
				if (gay->parent->right && gay->parent == grand_pa->left && gay->parent->right == gay){
					left_rotation(gay->parent);
					check_violation(original_parent);
				}
				else if (gay->parent->left && gay->parent == grand_pa->right && gay->parent->left == gay){
					right_rotation(gay->parent);
					check_violation(original_parent);
				}
				// line case //
				else{
					if (gay->parent == grand_pa->left && gay->parent->left && gay->parent->left == gay)
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
			
			if (parent && tmp == parent->left)
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

			if (parent && tmp == parent->left)	
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

		void Delete(T data){
			nil->parent->right = NULL;
			nil->right = NULL;
			if (first_elem())
				first_elem()->left = NULL;
			node *del = search(data);
			if (!del)
				return ;
			node *tmp = min(del);
			int original_color = 3;
			bool fake_node = false;

			if (del == NULL)
				return ;

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
					child = alloc.allocate(1);
					alloc.construct(child, node());
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
			this->_size--;
			nil->parent = last_elem();
			if (nil->parent)
				nil->parent->right = nil;
			if (first_elem())
				first_elem()->left = nil;
			nil->right = first_elem();
			del->clear();
			alloc.destroy(del);
			alloc.deallocate(del, 1);
		}
		
		void del_fix(node *fix){
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
				else if (special_case(sibling) == true)
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
 
		bool special_case(node *sibling){
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
		
	/******************************************** search utils ***********************************************/
		
		node *where(T data){
			node *tmp = root;
			node *tmp2 = tmp;
			while (tmp && tmp != nil){
				tmp2 = tmp;
				if (!comp(data, *tmp->data))
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			return tmp2;
		}

		node *find(T data) const{
			node *tmp = root;
			while (tmp && tmp != nil && tmp->data->first != data.first){
				if (comp(tmp->data->first, data.first))
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			if (tmp == nil)
				return NULL;
			return tmp;
		}

		node *search(T data) const{
			node *tmp = root;
			while (tmp && tmp != nil && *tmp->data != data){
				if (comp(*tmp->data, data))
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			if (tmp == nil)
				return NULL;
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

		node *first_elem() const{
			node *tmp = root;
			while (tmp && tmp->left && tmp->left != nil)
				tmp = tmp->left;
			return tmp;
		}

		node *last_elem() const {
			node *tmp = root;
			while (tmp && tmp->right && tmp != nil)
				tmp = tmp->right;
			return tmp;
		}

		

		void DownToUp(node *first, node *last){
			while (first && first != last){
				std::cout << first->data->first  << "\t" << first->data->second << "\n";
				first = next(first);
			}
		}

		void UpToDown(node *last, node *first){
			while (last && last != first){
				std::cout << last->data->first << "\t" << first->data->second << "\n";
				last = prev(last);
			}
		}
		
	/********************************************** getters **************************************************************/
		
		node *get_nil() const{
			return nil;	
		}
		
		size_type size() const{
			return this->_size;
		}

		node *get_root()const{
			return root;
		}
};

	template<class node>
	node *next(node *tree){
		node *tmp = tree;
		node *tmp2 = NULL;
		
		if (!tree || tree->nil)
			return NULL;
		if (tmp->right){
			tmp = tmp->right;
			while (tmp && tmp->left && !tmp->left->nil)
				tmp = tmp->left;
		}
		else if(tmp->parent && tmp->parent->left == tmp)
			return tmp->parent;
		else if (tmp->parent && tmp->parent->right == tmp){
			if (tmp->parent->parent)
				tmp2 = tmp->parent->parent;
			else
				return tmp->parent;
			while (tmp && tmp2 && tmp2->right == tmp->parent){
				tmp = tmp->parent;
				tmp2 = tmp2->parent;
			}
			tmp = tmp2;
		}
		return tmp;
	}
	
	template<class node>
	node *prev(node *tree){
		node *tmp = tree;
		node *tmp2 = NULL;
		
		if (!tree)
			return NULL;
		if (tree->nil)
			return tree->parent;
		
		if (tmp->left){
			tmp = tmp->left;
			while (tmp && tmp->right && !tmp->nil)
				tmp = tmp->right;
		}
		else if (tmp->parent && tmp->parent->right == tmp)
			return tmp->parent;
		else if (tmp->parent && tmp->parent->left == tmp){
			if (tmp->parent->parent)
				tmp2 = tmp->parent->parent;
			else
				return tmp->parent;
			while (tmp && tmp2 && tmp2->left == tmp->parent){
				tmp = tmp->parent;
				tmp2 = tmp2->parent;
			}
			tmp = tmp2;
		}
		return tmp;
	}

};





#endif
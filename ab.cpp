#include <iostream>
#include "ft.hpp"
#include "vector.hpp"
#include <vector>
// namespace ft{
// 	int i = 0;
// 	void print(){
// 		std::cout << "hello there\n";
// 	}
// 	template <class T>
// 	T sum(T a, T b){
// 		return a + b;
// 	}
// }

// void f(){
// 	int *c = new int[10];
// 	std::cout << "hey\n";
// 		throw "execption";
// }


int main()
{
	std::vector<int> p(5,5);
	
	std::vector<int>::iterator p1 = p.begin();
	std::vector<int>::iterator p2 = p.end();
	
	ft::vector<int>a(5, 5);

	ft::vector<int>::iterator a1 = a.begin();
	ft::vector<int>::iterator a2 = a.end();

	int i = p2 -p1;
	int y = a2 -a1;

	std::cout << "i : " << i << "\n";
	std::cout << "y : " << y << "\n";

	// system("leaks a.out");

}
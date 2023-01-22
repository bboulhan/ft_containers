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

template <class T>
void is_int (T x )
{
	

	std::is_integral<T> d;
	
	if (d.type == true)
		std::cout << "integral\n";
	else
		std::cout << "is not integral\n";
};



int main()
{
	ft::vector<int> a(2,2);
	ft::vector<int>::iterator it = a.begin();
	is_int(56);

	// system("leaks a.out");

}
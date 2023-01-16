#include <iostream>
#include <vector>
#include "vector.hpp"

template <class T>
class my_allocat : public std::allocator<T>{
	public:

	T *allocate(size_t size){
		std::cout << "size : " <<  size << std::endl;
		return new T[size];
	}
};





int main()
{
	// std::vector<int, my_allocat<int> > v(5, 2);
	// v.push_back(10);
	// v.push_back(20);
	// v.push_back(30);
	try{

	ft::vector<char> v;

	v.push_back(48);
	v.push_back(49);
	v.push_back(50);
	v.push_back(51);
	v.push_back(52);
	v.push_back(53);
	v.push_back(54);
	v.push_back(55);

	int i = 5;
	int *p = &i;

	// ft::vector<int>::iterator it = v.begin();
	// ft::vector<int>::iterator ite = v.end();
	// ft::vector<int>::iterator ab;

	// ab = it;


	// std::cout << *ab << "\t" << *ite << "\n";
	// std::cout << "ab : " << *ab << "\t it : " << *ite << "\n";


	// std::cout << *ab <<"\tp: " << *p << "\n****\n";
	
	
	// while (it != ite)
	// {
	// 	std::cout << *it << "\n";
	// 	it++;
	// }

	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;
	std::cout << "---------------------\n";

	std::cout << v.size() << "\t capacity : " << v.capacity() << "\n"; 
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}


}
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

	std::vector<int> v;

	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	v.push_back(16);


	int  *p = v.data();
	++p;
	*p = 42;
	// std::cout << *p << std::endl;
	// std::vector<int>::iterator it = v.begin();
	// std::vector<int>::iterator ite = v.end();

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
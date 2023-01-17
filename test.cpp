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
	
	std::vector<int> a(3,3);
	std::vector<int> v(2, 2);

	v.push_back(48);
	v.push_back(49);
	v.push_back(50);
	v.push_back(51);
	v.push_back(52);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);

	std::vector<int>::iterator ab = a.begin();
	std::vector<int>::iterator abb = a.end();
	
	
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();
	// std::vector<int>::iterator ab;

	v.insert(it, ab, abb);
	
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
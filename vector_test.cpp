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
	try{
	
	std::vector<int> v(1,1);

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

	std::vector<int>::iterator it = v.begin();
	
	it = v.erase(it + 1);
	it = v.erase(it + 1);
	it = v.erase(it + 1, it +3);
	it = v.erase(it + 1);

	it = v.begin();
	// std::vector<int>::iterator ab = it;

	while (it != v.end())
	{
		std::cout << *it << "\n";
		it++;
	};


	std::cout << "---------------------\n";
	std::cout << v.size() << "\t capacity : " << v.capacity() << "\n"; 
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}


}
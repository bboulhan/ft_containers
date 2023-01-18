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
	
	std::vector<int> v(2, 2);

	v.push_back(48);
	v.push_back(49);
	v.push_back(50);
	v.push_back(51);
	v.push_back(52);

	

	
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ab = it;

	// for(int  i = 1; i < 10;i++){
		// std::cout << "ab : " << *ab  << "\tit : "  << *it <<"\n";
		// std::cout << "adress ab : " << &(*ab)  << "\tit : "  << &(*it) <<"\n";
		// std::cout << v.size() << "\t capacity : " << v.capacity() << "\n"; 
	// v.insert(it, ab, abb);
	// 	ab = v.insert(it, i*100);
		// std::cout << "ab : " << *ab  << "\tit : "  << *it <<"\n";
		// std::cout << "adress ab : " << &(*ab)  << "\tit : "  << &(*it) <<"\n";
	// }
	it = v.insert(it, 100);
	it = v.insert(it, 200);
	it = v.insert(it, 300);

	char i = v.begin() - v.end() ;

	it = v.begin();
	
	
	while (it != v.end())
	{
		std::cout << *it << "\t adrees "  << &(*it)<< "\n";
		it++;
	}
	std::cout << "---------------------\n";

	// for (int i = 0; i < v.size(); i++)
	// 	std::cout << v[i] << std::endl;

	std::cout << "---------------------\n";
	std::cout << v.size() << "\t capacity : " << v.capacity() << "\n"; 
	std::cout << i << "\n";
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}


}
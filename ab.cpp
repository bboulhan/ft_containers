#include <iostream>
// #include "ft.hpp"
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

	template<class T>
	T *add(T *data, T elem, unsigned int size){
		std::cout << "hey\n";
		std::allocator<T> alloc;
		T *tmp;
		tmp = alloc.allocate(size + 1);
		for(unsigned int i = 0; i < size; i++)
			alloc.construct(tmp + i, data[i]);
		alloc.construct(tmp + size, elem);
		alloc.deallocate(data, size);
		return tmp;
	}



int main()
{
	std::allocator<int> ibra;

	int *arr = ibra.allocate(6);

	for(int  i = 0; i < 6;i++){
		ibra.construct(arr + i, i + 48);
		std::cout << arr[i] << "\n";
	}
	std::cout << "--------\n";

	arr = add(arr, 222, 6);

	for(int i = 0;i < 7; i++){
		std::cout << arr[i] << "\n";
	}

/**********************************/

	// int *arr = new int[6];
	// for(int i = 0;i < 6;i++)
	// 	arr[i] = (i + 1) * 10;
	
	// arr = ad(arr, 555, 6);

	// for(int i = 0;i < 7; i++){
	// 		std::cout << arr[i] << "\n";
	// }


	// system("leaks a.out");

}
#include <iostream>

namespace ft{
	int i = 0;
	void print(){
		std::cout << "hello there\n";
	}
	template <class T>
	T sum(T a, T b){
		return a + b;
	}
}

void f(){
	int *c = new int[10];
	std::cout << "hey\n";
		throw "execption";
}


int main()
{
	std::allocator<char> ibra;

	char *arr = ibra.allocate(6);

	for(int  i = 0; i < 5;i++){
		ibra.construct(arr + i, i + 48);
		std::cout << arr[i] << "\n";
	}
	ibra.construct(arr + 5, 0);
	ibra.destroy(arr);
	ibra.deallocate(arr, 6);
	char *str = ibra.allocate(6);
	strcpy(str, "hello");
	
	std::cout << "--------\n";
	void *p = &arr[0];
	void *d = &str[0];
	
	std::cout << arr << "\t" << p << "\n";
	std::cout << str << "\t" << d << "\n";

	// system("leaks a.out");
	// for(int i = 0;i < 5; i++){
	// 	std::cout << arr[i] << "\n";
	// }

}
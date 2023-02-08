#include <iostream>
#include <vector>
#include "vector.hpp"
// #include "ft.hpp"
#define _ratio 1


void test2(){
	std::vector<int>  vector;
    std::vector<int> tmp, tmp2;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 5);
 	// vector.assign(1000, 1);
	vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    // vector.insert(vector.end() - 50, 4200 * _ratio , 2);
	std::vector<int>::iterator it = vector.begin();
	for (;it != vector.end();it++)
		std::cout << *it << "\n";
}


void test(){
	ft::vector<int>  vector;
    ft::vector<int> tmp, tmp2;
    tmp.assign(2600 * _ratio, 1);
    // vector.assign(4200 * _ratio, 5);
    // vector.assign(1000, 1);
    // vector.insert(vector.end() - 50, 4200 * _ratio , 2);
	vector.insert(vector.begin(), 40, 4);
	// vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
	ft::vector<int>::iterator it = vector.begin();
	for (;it != vector.end();it++)
		std::cout << *it << "\n";

}



int main()
{
	try{
		// test2();
		test();
		// test3();
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	// system("leaks a.out");


}
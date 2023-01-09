#include <iostream>
#include <cmath>


	void f3() {
	int  i = 0;
	try{
	int *c = new int[100]; // will be leak
	std::string s = "this is stack... would be destroyed";
	throw "exception!";
	}
	catch(...){
		std::cout << "hh\n";
		i = 1;
	}
	if (i == 1)
		throw("adfa");
	}

	void f2() { f3(); }

	void f1() { try { f3(); } catch (...) { std::cout << "back to here!\n"; } }

int main(int ac, char  **av)
{
	// try{
	// 	int *c = new int[100]; // will be leak
	// std::string s = "this is stack... would be destroyed";
	// throw "exception!";
	// }
	// catch (...) { std::cout << "back to here!\n"; }
	f1();
	system("leaks a.out");
	
}
#include "ft.hpp"
#include "map.hpp"
// #include "vector.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
# define _ratio 1
# define T int
# define V int



void test2(){
	std::map<int, int> mp;

    for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    
	std::map<T, V> mp2;
    for (int i = 25 * _ratio, j = 0; i < 35 * _ratio; ++i, j--)
        mp.insert(std::make_pair(i, j));

    // long *adr1 = reinterpret_cast<long *>(&mp);
    // long *adr2 = reinterpret_cast<long *>(&mp2);
    mp.swap(mp2);
    std::swap(mp, mp2);
    std::map<T, V>::iterator it = mp2.begin();
	while (it != mp2.end()){
		std::cout << it->first << "\n";
		it++;
	}
	std::cout << "-----------------------------------------\n";

    std::map<T, V>::iterator it2 = mp.begin();
	while (it2 != mp.end()){
		std::cout << it2->first << "\n";
		it2++;
	}

}







void test(){
	ft::map<int, int> mp;

    for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
    
	ft::map<T, V> mp2;
    for (int i = 25 * _ratio, j = 0; i < 35 * _ratio; ++i, j--)
        mp.insert(ft::make_pair(i, j));

    // long *adr1 = reinterpret_cast<long *>(&mp);
    // long *adr2 = reinterpret_cast<long *>(&mp2);
	// std::cout << "hey\n";
    mp.swap(mp2);
	// std::cout << "hey 2\n";
    // ft::swap(mp, mp2);
    ft::map<T, V>::iterator it = mp2.begin();
	while (it != mp2.end()){
		std::cout << it->first << "\n";
		it++;
	}
	std::cout << "-----------------------------------------\n";

    ft::map<T, V>::iterator it2 = mp.begin();
	while (it2 != mp.end()){
		std::cout << it2->first << "\n";
		it2++;
	}
}


int main()
{
	test();
	// test2();
	system("leaks a.out");
	return 0;
}


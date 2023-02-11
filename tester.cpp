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
    std::vector<int> v;

    mp.insert(std::make_pair(5, 5));
    mp.insert(std::make_pair(3, 3));
    mp.insert(std::make_pair(7, 7));

    std::map<T, V>::reverse_iterator rit = mp.rbegin();
    std::map<T, V>::reverse_iterator rit2 = mp.rend();
    v.push_back(rit->first);
    rit++;
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    rit++;
    v.push_back(*rit == *rit2);
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back((--rit)->first);
    v.push_back((++rit2)->first);
    v.push_back((rit--)->first);
    v.push_back((rit2++)->first);
	// std::cout << "-----------------------------------------\n";

	std::vector<int>::iterator it = v.begin();
	for(;it != v.end();it++)
		std::cout << *it << "\n";

}







void test(){
	ft::map<int, int> mp;
    std::vector<int> v;

    mp.insert(ft::make_pair(5, 5));
    mp.insert(ft::make_pair(3, 3));
    mp.insert(ft::make_pair(7, 7));

    ft::map<T, V>::reverse_iterator rit = mp.rbegin();
    ft::map<T, V>::reverse_iterator rit2 = mp.rend();

    v.push_back(rit->first);
    rit++;
    rit2--;
    v.push_back(rit->first);
	std::cout << "hey\n";
    v.push_back(rit2->first);
	std::cout << "hey 2\n";
    rit++;
    v.push_back(*rit == *rit2);
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back((--rit)->first);
    v.push_back((++rit2)->first);
    v.push_back((rit--)->first);
    v.push_back((rit2++)->first);
	// std::cout << "-----------------------------------------\n";

	std::vector<int>::iterator it = v.begin();
	for(;it != v.end();it++)
		std::cout << *it << "\n";
}


int main()
{
	// test2();
	// std::cout << "-----------------------------------------\n";
	test();
	// system("leaks a.out");
	return 0;
}


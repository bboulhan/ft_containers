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
    std::map<T, V> mp;
    std::map<int, int, std::greater<int> > mp2;
    mp.insert(std::make_pair(10, 10));
    mp2.insert(std::make_pair(10, 10));
    if (mp.upper_bound(11) == mp.end())
       std::cout << "true\n";
    if (mp2.upper_bound(1) == mp2.end())
       std::cout << "true 2 \n";
        
    mp.insert(std::make_pair(20, 20));
    mp.insert(std::make_pair(30, 30));
    mp.insert(std::make_pair(40, 40));
    mp.insert(std::make_pair(50, 50));
    mp.insert(std::make_pair(60, 60));
    mp2.insert(std::make_pair(20, 20));
    mp2.insert(std::make_pair(30, 30));
    mp2.insert(std::make_pair(40, 40));
    mp2.insert(std::make_pair(50, 50));
    mp2.insert(std::make_pair(60, 60));
    std::map<int, int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = mp.upper_bound(i);
		std::cout << it->first << std::endl;
    }
    for (int i = 11; i < 70; i += 10) {
	std::cout << "hey\n";
        it = mp2.upper_bound(i);
		std::cout << it->first << "\tdata : " << it->second << std::endl;
    }
    std::map<int, int> mp3;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
        mp3.insert(std::make_pair(i, j));
    }
    std::map<int, int> mp4;
    mp.insert(std::make_pair(-10, 10));
    mp.insert(std::make_pair(-20, 20));
	std::cout << (--mp.upper_bound(0))->first << "\n";
    mp3.upper_bound(49 * _ratio);

}

void test(){
	ft::map<T, V> mp;
    ft::map<int, int, std::greater<int> > mp2;
    mp.insert(ft::make_pair(10, 10));
    mp2.insert(ft::make_pair(10, 10));
    if (mp.upper_bound(11) == mp.end())
       std::cout << "true\n";
    if (mp2.upper_bound(1) == mp2.end())
       std::cout << "true 2 \n";
        
    mp.insert(ft::make_pair(20, 20));
    mp.insert(ft::make_pair(30, 30));
    mp.insert(ft::make_pair(40, 40));
    mp.insert(ft::make_pair(50, 50));
    mp.insert(ft::make_pair(60, 60));
    mp2.insert(ft::make_pair(20, 20));
    mp2.insert(ft::make_pair(30, 30));
    mp2.insert(ft::make_pair(40, 40));
    mp2.insert(ft::make_pair(50, 50));
    mp2.insert(ft::make_pair(60, 60));
    ft::map<int, int>::iterator it;
    for (int i = 1; i < 60; i += 10) {
        it = mp.upper_bound(i);
		std::cout << it->first << std::endl;
    }
    for (int i = 11; i < 70; i += 10) {
	std::cout << "hey\n";
        it = mp2.upper_bound(i);
		std::cout << it->first << "\tdata : " << it->second << std::endl;
    }
    std::map<int, int> mp3;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
        mp3.insert(std::make_pair(i, j));
    }
    std::map<int, int> mp4;
    mp.insert(ft::make_pair(-10, 10));
    mp.insert(ft::make_pair(-20, 20));
	std::cout << (--mp.upper_bound(0))->first << "\n";
    mp3.upper_bound(49 * _ratio);
}


int main()
{
	// test2();
	test3();
	std::cout << "-----------------------------------------\n";
	// test();
	test4();
	// system("leaks a.out");
	return 0;
}


#include "ft.hpp"
#include "map.hpp"
// #include "vector.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
# define _ratio 1



// void test2(){
// 	std::map<int, int> mp;
//     std::vector<int> v;
//     v.push_back(mp.erase(3));
//     for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
//         mp.insert(std::make_pair(i, j));
//     std::map<int,int>::iterator it = mp.begin();
//     v.push_back(it->first);
//     v.push_back(mp.erase(-5));
//     v.push_back(mp.size());
//     v.push_back(mp.erase(0));
//     v.push_back(mp.size());
//     it = mp.begin();
//     v.push_back(it->first);
//     std::map<int, int>::iterator it4 = mp.begin();
//     for (; it4 != mp.end(); it4 = mp.begin())
//         mp.erase(it4->first);
//     v.push_back(mp.erase(30 * _ratio - 1));
//     v.push_back(mp.size());
//     std::map<int, int> mp2;
//     for (int i = 0, j = 0; i < 10 ; ++i, ++j)
//         mp2.insert(std::make_pair(i, j));
//     mp2.erase(2);
//     mp2.erase(7);
//     std::map<int ,int>::iterator it3 = mp2.begin();
//     for (; it3 != mp2.end(); ++it3) {
//         v.push_back(it3->first);
//         v.push_back(it3->second);
//     }
// }






void test(){
	ft::map<int, int> mp ;
    std::vector<int> v;
    for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
	// mp.display();
    

	ft::map<int, int> mp2;
    mp2.insert(mp.begin(), mp.end());
 

    ft::map<int, int>::iterator it2 = mp2.begin();
    for (; it2 != mp2.end(); ++it2) {
        v.push_back(it2->first);
        v.push_back(it2->second);
    }
	std::cout << mp2.begin()->first << "\n";
	std::cout << &(*mp2.end()) << "\n";
	mp2.display();

}


int main()
{
	test();
	// test2();
	// system("leaks a.out");
	return 0;
}


#include "ft.hpp"
#include "map.hpp"
// #include "vector.hpp"
#include <vector>
#include <map>

int main(){
	ft::map<int, int> m;
	std::vector<int> v;

	m.clear();
	for (int i = 0, j = 0; i < 25; ++i, ++j)
		m.insert(ft::make_pair(i, j));
	v.push_back(m.size());
	m.display();
	m.clear();
	v.push_back(m.size());
	ft::map<int, int>::iterator it = m.begin();
	if (it == m.end())
		v.push_back(1);
	std::cout << "here 1\n";
	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;
	std::cout << v[2] << std::endl;
	return 0;
}


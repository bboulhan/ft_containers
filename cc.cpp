#include <iostream>
#include <cmath>
#include <vector>
#include <map>


int main()
{
	std::map<int, std::string> ab;

	ab.insert(std::pair<int, std::string>(11, "A11"));
	ab.insert(std::pair<int, std::string>(15, "B15"));
	ab.insert(std::pair<int, std::string>(8, "C8"));
	ab[22] = "D22";
	ab[13] = "E13";

	std::map<int, std::string>::iterator it = ab.begin();

	while (it != ab.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}

	void left_rotation(node *tree);
	node *where(T data);
	void replace(node *del, node *tree);
	node *search(T data);
	node *max(node *del);
	node *min(node *del);
	void Delete(T data);
	void del_fix(node *fix);
	bool special_case(node *sibling, node *fix);
	void clean(node *trash);
	node *first_elem();
	node *last_elem();
	node *next(node *tree);
	void all_elem(node *first, node *last);
	size_type size() const;



	return 0;
}
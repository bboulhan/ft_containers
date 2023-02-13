#include <iostream>
#include <vector>
#include "vector.hpp"
#include "ft.hpp"
#include "stack.hpp"
#include <stack>



int main()
{
	std::stack<int> q;

	for(int i = 1; i < 15; i++)
		q.push(i);
	
	std::cout << q.top() << std::endl;
	std::cout << q.top() << std::endl;

	for (int i = 0; i < q.size(); i++)
		std::cout << q.top() << std::endl;




	std::cout << "###################################\n";

	ft::stack<int> p;
	ft::stack<int> x;

	for (int i = 1; i < 15; i++)
		x.push(i);


	for (int i = 1; i < 15; i++)
		p.push(i);
	
	if (x == p)
		std::cout << "true\n";



	
	for (int i = 0; i < p.size(); i++)
		std::cout << p.top() << std::endl;










	return 0;

}

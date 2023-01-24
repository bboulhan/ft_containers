#include <iostream>
#include "ft.hpp"
#include "vector.hpp"
#include <vector>

class person{
	int age;
	std::string name;
	public:
		person(int age, std::string name){
			this->age = age;
			this->name = name;
		}
		int getAge(){
			return (this->age);
		}
		std::string getName(){
			return (this->name);
		}
		friend void print(person &p);

};

void print(person &p){
	p.age = 22;
	p.name = "frisa";
	std::cout << "age : " << p.age << std::endl;
	std::cout << "name : " << p.name << std::endl;
}


int main()
{
	person ibra(21, "ibra");
	print(ibra);
	std::cout << "age : " << ibra.getAge() << std::endl;
	std::cout << "name : " << ibra.getName() << std::endl;
	// system("leaks a.out");

}
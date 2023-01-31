
#include <iostream>
#include "ft.hpp"
#include "vector.hpp"
#include <vector>

template<class T, class Alloc = std::allocator<T> >
class person{
	int age;
	T *name;
	public:
	Alloc alloc;
		person() : age(21) {
			name = alloc.allocate(1);
			alloc.construct(name, "ibra");
		};
		person(int age, T name){
			this->age = age;
			this->name = alloc.allocate(1);
			alloc.construct(this->name, name);
		}
		int getAge(){
			return (this->age);
		}
		T *getName(){
			return (this->name);
		}
		template<class S>
		friend void print(person<S> *p);

};

template<class S>
void print(person<S> *p){
	// p.age = 22;
	// p.name = "frisa";
	std::cout << "age : " << p->age << std::endl;
	std::cout << "name : " << *p->name << std::endl;
}


int main()
{
	std::allocator<person<std::string> > alloc;

	person<std::string> *ab;
	ab = alloc.allocate(1);
	alloc.construct(ab, person<std::string>(10, "kkk"));
	print(ab);

	// system("leaks a.out");

}
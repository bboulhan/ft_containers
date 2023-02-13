#include <iostream>
#include <vector>
#include "vector.hpp"
// #include "ft.hpp"
#define _ratio 100

class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
	char *get_ex(){return l;}
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

void test2(){
	std::vector<int>  vector;
    // std::vector<int> tmp;
    // tmp.assign(26 * _ratio, 1);
    // vector.assign(42 * _ratio, 1);
    // vector.insert(vector.end() - 10 * _ratio, tmp.begin(), tmp.end());

	// std::cout << "size : " << vector.size() << "\tcapacity : " << vector.capacity()<< "\n";
	// std::vector<int>::iterator it = vector.begin();
	// for (;it != vector.end();it++)
	// 	std::cout << *it << "  "; 

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
	// std::vector<B*>::iterator it = v1.begin();
	// for (;it !=v1.end(); it++)
	// 	std::cout << (*it)->get_ex() << "\n";
	std::cout << "size : " << v1.size() << "\tcapacity : " << v1.capacity()<< "\n";
    try { 

		vv.insert(vv.begin(), v1.begin(), v1.end()); }
	catch (...) {
        std::cout << "size : " << vv.size() << "\tcapacity : " << vv.capacity()<< "\n";
    }
}


void test(){
	ft::vector<int>  vector;
    // ft::vector<int> tmp;
    // tmp.assign(26 * _ratio, 1);
    // vector.assign(42 * _ratio, 1);
    // vector.insert(vector.end() - 10 * _ratio, tmp.begin(), tmp.end());

    // ft::vector<int>::iterator it = vector.begin();
	// for (;it != vector.end();it++)
	// 	std::cout << *it << "  "; 
	
	// std::cout << "size : " << vector.size() << "\tcapacity : " << vector.capacity()<< "\n";
	
	std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1; 
	// std::cout << "ibra\n";
    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
	// ft::vector<B*>::iterator it = v1.begin();
	// for (;it !=v1.end(); it++)
	// 	std::cout << (*it)->get_ex() << "\n";

	std::cout << "size : " << v1.size() << "\tcapacity : " << v1.capacity()<< "\n";
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
	catch (...) {
        std::cout << "size : " << vv.size() << "\tcapacity : " << vv.capacity()<< "\n";
    }



}



int main()
{
	try{
		test2();
		std::cout << "-------------------------------\n";
		test();
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------\n";
	system("leaks a.out");


}
#include <iostream>
#include <vector>
#include "vector.hpp"
// #include "ft.hpp"
#define _ratio 1

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
    std::vector<int> tmp;
    // tmp.assign(2600 * _ratio, 1);
    // vector.assign(4200 * _ratio, 1);
    // vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
	std::vector<B*>::iterator it = v1.begin();
	for (;it !=v1.end(); it++)
		std::cout << (*it)->get_ex() << "\n";
	std::cout << "size : " << v1.size() << "\tcapacity : " << v1.capacity()<< "\n";
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
	catch (std::exception &e) {
        // std::cout << "size : " << vv.size() << "\tcapacity : " << vv.capacity()<< "\n";
	std::cout << e.what() << "\n";
	}
	catch (...) {
        std::cout << "size : " << vv.size() << "\tcapacity : " << vv.capacity()<< "\n";
    }
}


void test(){
	ft::vector<int>  vector;
    ft::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1;
	// std::cout << "hey\n";
    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
	// ft::vector<B*>::iterator it = v1.begin();
	// for (;it !=v1.end(); it++)
	// 	std::cout << (*it)->get_ex() << "\n";


	std::cout << "size : " << v1.size() << "\tcapacity : " << v1.capacity()<< "\n";
    // try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
	// catch (...) {
    //     std::cout << "size : " << vv.size() << "\tcapacity : " << vv.capacity()<< "\n";
    // }
	// std::cout << "hey 2 \n";



}

void test3(){
	std::vector<int> vector;
    for (int i = 0; i < 99 * _ratio; ++i)
        vector.push_back(i);
    vector.erase(vector.begin() + 8 * _ratio, vector.end() - 15 * _ratio);
	std::vector<int>::iterator it = vector.begin();
	for (;it != vector.end();it++)
		std::cout << *it << "   ";
	std::cout << "\n";
	
}

void test4(){
	ft::vector<int> vector;
    for (int i = 0; i < 99 * _ratio; ++i)
        vector.push_back(i);
    vector.erase(vector.begin() + 8 * _ratio, vector.end() - 15 * _ratio);
	ft::vector<int>::iterator it = vector.begin();
	for (;it != vector.end();it++)
		std::cout << *it << "   ";
	std::cout << "\n";
	
}


int main()
{
	try{
		// test2();
		// std::cout << "----------------------\n";
		// test();
		test3();
		std::cout << "----------------------\n";
		test4();
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	// system("leaks a.out");


}
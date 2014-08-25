#include <iostream>
#include <string>

using namespace std;


class Cat {
public: 
	Cat(const string &name)
       	: name_(name){
		cout << name_ << " says Myau!!!\n";
	}
	~Cat() {
		cout << name_ << " says Murrr, Myau!!!\n";
	}
	void AskFood()const {
		cout << name_ << " says I am hungry!!!!!!! Give me food!!!!!\n";
	}

private:
	string name_;
};

template<typename T>
class SmartPointer {
public:
	SmartPointer(T *p_cat)
       	: p_cat_(p_cat){
		
	}
	
	~SmartPointer() {
		delete p_cat_;
	}

	T *operator->()const {
		return p_cat_;
	}
	T &operator*()const {
		return *p_cat_;
	}

private:
	T* p_cat_;

	SmartPointer operator=(T *p_cat);
};



int main(int argc, char *argv[]) {
	
	
	SmartPointer<Cat> p_some_cat(new Cat("Barsik"));


	p_some_cat->AskFood();
	(*p_some_cat).AskFood();

	return 0;
}

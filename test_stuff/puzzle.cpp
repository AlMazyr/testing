#include <iostream>

using namespace std;

int foo() {
	cout << "Hello.\n";
	return 2;
}

int bar() {
	int *m[1];
	m[3] = (int*)&foo;
	return 0;
}


int main() {

	bar();

	return 0;
}

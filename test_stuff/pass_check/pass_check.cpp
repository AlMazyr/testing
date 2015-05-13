// Programm reads string form  stdin.
// If string contains uppercase and lowercase characters and digits,
// then programm writes yes to stdout, else no.
// String can contains only latin characters and digits.
// Author: A. Mazyrin, algoritmist1618@gmail.com

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

	bool is_lower = false, is_upper = false, is_digit = false;

	ifstream f_in("input.txt");
	ofstream f_out("output.txt");

	char x = 0;
	int len = 0;
	while(f_in.get(x)) {
		len++;
		if ((x >= '0') && (x <= '9')) {
			is_digit = true;
		} else if((x >= 'a') && (x <= 'z')) {
			is_lower = true;
		} else if((x >= 'A') && (x <= 'Z')) {
			is_upper = true;
		}

		if((is_digit == true) && (is_lower == true) && (is_upper == true) && (len >= 8)) {
			f_out << "yes";
			return 0;
		}
	}

	f_out << "no";
	return 0;
}

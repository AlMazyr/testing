// Programm reads string form  stdin.
// If string contains uppercase and lowercase characters and digits,
// then programm writes yes to stdout, else no.
// String can contains only latin characters and digits.
// Author: A. Mazyrin, algoritmist1618@gmail.com

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	bool is_lower = false, is_upper = false, is_digit = false;

	char x = 0;
	int len = 0;
	while((x = cin.get()) != '\n') {
		len++;
		if ((x >= 48) && (x <= 57)) {
			is_digit = true;
		} else if((x >= 97) && (x <= 122)) {
			is_lower = true;
		} else if((x >= 65) && (x <= 90)) {
			is_upper = true;
		}

		if((is_digit == true) && (is_lower == true) && (is_upper == true) && (len >= 8)) {
			cout << "yes";
			return 0;
		}
	}

	cout << "no";

	return 0;
}

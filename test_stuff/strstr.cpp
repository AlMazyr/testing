#include <iostream>

using namespace std;

int strstr(const char *str, const char *pattern) {
    int res = -1, i = 0;
    const char *p_str = str;
    
    while(*p_str) {
        if(*p_str == pattern[i]) {
            if(pattern[i + 1] == 0) {
                res = (p_str - i) - str;
                break;
            }
            i++;
        }
        else {
	    if(i != 0) {
	      p_str--;
              i = 0;
	    }
        }
	p_str++;
    }
    
    return res;
}

int main() {
  char str1[20], str2[20];

  cin >> str1 >> str2;

  int res = strstr(str1, str2);

  cout << res << endl;
}

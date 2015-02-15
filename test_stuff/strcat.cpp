#include <iostream>

using namespace std;

void cin_reverse(){
    int x;
    cin >> x;
    if(!x) return;
    cin_reverse();
    cout << x << ' ';
}


void strcat(char *to, const char *from) {
	    while(*to++);
	       to--;
	        
	    while(*from) {
			*to++ = *from++;
		}
}

int main()
{

	char str1[14], str2[7];
	
	cin >> str1 >> str2;

	strcat(str1, str2);
	
	cout << endl;
	cout << str1 << endl;

	    return 0;
	        
 }

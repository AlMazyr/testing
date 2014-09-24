#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int i = 1, flag = 0;
	
	if(argc < 2)
		return 0;

    if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n') {
        flag = 1;
        argc++;
        argv--;
    }

	for(i = 1; i < argc; ++i) {
        fputs(argv[i], stdout);
        if(i < argc - 1)
            putchar(' ');
	}

	if(!flag)
		putchar('\n');

	return 0;
}

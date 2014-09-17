#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int i = 1, flag = 0;
	
	if(argc < 2)
		return 0;
		
	if(!memcmp(argv[1], "-n", 2)) {
		flag = 1;
		i = 2;
	}

	for(; i < argc; ++i) {
		printf("%s ", argv[i]);
	}

	if(!flag)
		printf("\n");

	return 0;
}

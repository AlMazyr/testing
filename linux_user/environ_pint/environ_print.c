#include <stdio.h>


int main(int argc, char *argv[], char *envp[]) {
	
	puts("Printing environment:");
	int i = 0;
	while(envp[i] != NULL) {
		puts(envp[i++]);

	}
	puts("Printing argv:");
	for(i = 0; i < argc; ++i) {
		printf("%s, ", argv[i]);		
	}
	puts(" ");
	return 0;
}

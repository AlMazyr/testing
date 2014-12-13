#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) {
	
	if(argc < 3) {
		fprintf(stderr, "Err arguments. Usage %s <PROGRAMM> <ARG1>\n", argv[0]);
		return -1;
	}

	(void)execle(argv[1], argv[1], argv[2], 0, envp);

	printf("Error on programm start: %s.\n", strerror(errno));
	exit(-1);

	return 0;
}

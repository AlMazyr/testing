#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Err args. Usage %s <TEST_STRING>.\n", argv[0]);
		return -1;
	}
	
	int str_sz = 0;
	int pipe_fd[2];
	ssize_t cnt = 0;
	char *str = argv[1];
	char read_str[64] = {0};

	// Calculates string size.
	while(*str++)
		++str_sz;
	str = argv[1];

	// Creates pipe.
	if(pipe(pipe_fd) == -1) {
		fprintf(stderr, "Can't create pipe. Err: %s.\n", strerror(errno));
		return -1;
	}

	// Writes to pipe.
	cnt = write(pipe_fd[1], str, str_sz + 1);
        if(cnt < str_sz) {
		fprintf(stderr, "Can't write to pipe. Err = %s.\n", strerror(errno));
		return -1;
	}	

	// read from pipe
	cnt = read(pipe_fd[0], read_str, str_sz + 1);
        if(cnt < str_sz) {
		fprintf(stderr, "Can't read from pipe. Err = %s.\n", strerror(errno));
		return -1;
	}	
	
	printf("Readed from pipe: %s.\n", read_str);

	close(pipe_fd[0]);
	close(pipe_fd[1]);

	return 0;
}

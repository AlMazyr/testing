#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	
	int pipe_fd[2], res = 0;
	uint32_t pipe_size = 0;
	int8_t test;

	res = pipe2(pipe_fd, O_NONBLOCK);
	if(res == -1) {
		fprintf(stderr, "Can't create pipe.\n");
		return -1;
	}

	while((res = write(pipe_fd[1], &test, 1)) != -1) {
		pipe_size++;
	}

	printf("Pipe size is %d.\n", pipe_size);

	close(pipe_fd[0]);
	close(pipe_fd[1]);

	return 0;
}

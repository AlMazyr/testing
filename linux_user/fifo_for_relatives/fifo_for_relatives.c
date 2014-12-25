#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Err args. Usage %s <FIFO_NAME>.\n", argv[0]);
		return -1;
	}

	const char *str = "It works, bitches.";
	umask(0);
	if(mkfifo(argv[1], 0660) == -1) {
		fprintf(stderr, "Err in mkfifo call: %s.\n", strerror(errno));
		return -1;
	}

	pid_t pid = 0;

	pid = fork();
	if(pid == -1) {
		fprintf(stderr, "Err in fork call: %s.\n", strerror(errno));
		return -1;
	}	
	else if(pid == 0) { // child
		char read_buff[32];
		int fifo_fd = open(argv[1], O_RDONLY), cnt = 0;
		cnt = read(fifo_fd, read_buff, 20);
		if(cnt < sizeof(str)){
			fprintf(stderr, "Err in read call: %s.\n", strerror(errno));
			return -1;
		}
		printf("Readed from fifo: %s.\n", read_buff);

		puts("Child exit.");
		close(fifo_fd);

	}else { // parent
		int fifo_fd = open(argv[1], O_WRONLY), cnt = 0;
		cnt = write(fifo_fd, str, 20); 
		if(cnt < sizeof(str)){
			fprintf(stderr, "Err in write call: %s.\n", strerror(errno));
			return -1;
		}
		puts("Parent exit.");
		close(fifo_fd);
	}


	return 0;
}

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
		fprintf(stderr, "Err args. Usage %s <FIFO_PATH>.\n", argv[0]);
		return -1;
	}
	int fifo_fd = open(argv[1], O_WRONLY), cnt = 0;
	if(fifo_fd < 0) {
		fprintf(stderr, "Err in open syscall: %s.", strerror(errno));
		return -1;
	}
	char ch = 0;

	while((ch = getchar()) != EOF) {
		cnt = write(fifo_fd, &ch, 1);
		if(cnt < 1) break;
	}

	close(fifo_fd);
	return 0;
}

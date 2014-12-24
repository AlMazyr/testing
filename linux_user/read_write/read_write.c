#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	if(argc != 2) {
		fprintf(stderr, "Err arguments. Usage %s <FILE>.\n", argv[0]);
		return 1;
	}

	int fd = 0;
	ssize_t cnt = 0;
	char ch;

	// setting new umask for process.
	(void)umask(0);

	// opening file.
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		fprintf(stderr, "Can't open file %s. Err description: %s.\n", argv[1], strerror(errno));
		return -1;
	}

	printf("Reading file %s:\n", argv[1]);

	// reading file.
	while((cnt = read(fd, &ch, 1)) > 0) {
		putchar(ch);
	}
	if(cnt == -1) {
		fprintf(stderr, "Err while reading file %s: %s.\n", argv[1], strerror(errno));
		return -1;
	}
	putchar('\n');
	

	close(fd);

	return 0;
}

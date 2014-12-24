#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Err args. Usage %s <TEST_STRING>.\n", argv[0]);
		return -1;
	}


	ssize_t cnt = 0;
	int str_sz = 0;
	char *str_p = argv[1];

	while(*str_p++) str_sz++;

	pid_t pid = 0;
	int pipe_fd[2];
	if(pipe(pipe_fd)) {
		fprintf(stderr, "Err pipe call: %s.\n", strerror(errno));
		return -1;
	}

	pid = fork();

	switch(pid) {
		
		case -1: // err
			fprintf(stderr, "Error in fork: %s.\n", strerror(errno));
			return -1;
			break;

		case 0: // child
			close(pipe_fd[1]);

			char local_str[64] = {0};
			cnt = read(pipe_fd[0], local_str, str_sz + 1);
			if(cnt != (str_sz + 1)) {
				fprintf(stderr, "Can't read from pipe: %s.\n", strerror(errno));
				return -1;
			}
			printf("<%s> is readed from pipe.\n", local_str);

			break;

		default: // parent
			close(pipe_fd[0]);

			cnt = write(pipe_fd[1], argv[1], str_sz + 1);
			if(cnt != (str_sz + 1)) {
				fprintf(stderr, "Can't write in pipe: %s.\n", strerror(errno));
				return -1;
			}
		
			printf("Write <%s> to pipe is Ok.\n", argv[1]);	
			break;
		
	}



	return 0;
}

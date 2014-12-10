#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]) {

	pid_t pid;

	printf("Hello! I am process. My PID = %d.\n", getpid());

	pid = fork();
	if(pid == -1) {
		fprintf(stderr, "fork fail. err: %s.\n", strerror(errno));
	} else if(pid == 0) {
		printf("Hello! I am child process. My PID = %d.\n", getpid());
	} else {
		printf("Hello! I am parent process. My PID = %d, My child's PID = %d.\n", getpid(), pid);
	}


	return 0;
}

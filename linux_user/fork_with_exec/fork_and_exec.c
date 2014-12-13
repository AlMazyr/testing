#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	pid_t pid;

	printf("Hello!. I am the new process. My PID is %d.\n", getpid());

	puts("Forking.");

	pid = fork();
	if(pid == -1) {
		fprintf(stderr, "Fork error: %s.\n", strerror(errno));
		return -1;
	} else if(pid == 0) {
		printf("I am child process! My PID is %d. My parent PID is %d.\n", getpid(), getppid());
		execlp("echo", "echo", "Hello!", 0);
		
		fprintf(stderr, "Fail on start programm. Err: %s.\n", strerror(errno));
		return -1;

	} else {
		printf("I am parent process. My PID is %d. My child's PID is %d.\n", getpid(), pid);
	}

	return 0;
}

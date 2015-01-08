#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>


void *thread1(void* n_) {
	int n = *(int*)n_, i = 0;
	
	while(n--) {
		sleep(1);
		printf("Hi, I am thread1, i = %d.\n", ++i);
	}
	puts("End of thread1.");
	return NULL;
}


void *thread2(void* n_) {
	int n = *(int*)n_, i = 0;
	
	while(n--){
		sleep(1);
		printf("Hi, I am thread2, i = %d.\n", ++i);
	}
	puts("End of thread2.");
	return NULL;
}

int main(int argc, char *argv[]) {
	
	static int n = 0;
	int err = 0;
	pthread_t thr1, thr2;
	puts("Hello, user!\nPlease input count of threads iterations!");
	scanf("%d", &n);
	puts("Thank you!\nStarting 2 threads!");

	// Starting two threads.
	if((err = pthread_create(&thr1, (pthread_attr_t *)NULL, thread1, &n)) != 0) {
		fprintf(stderr, "Can't create thread1: %s.\n", strerror(err));		
		thr1 = 0;
	} else {
		printf("Thread1 with id = %d starts!\n", (int)thr1);
	}
	if((err = pthread_create(&thr2, NULL, thread2, &n)) != 0) {
		fprintf(stderr, "Can't create thread2: %s.\n", strerror(err));		
		thr2 = 0;
	} else {
		printf("Thread2 with id = %d starts!\n", (int)thr2);
	
	}
	
	// waiting until the end of the threads	
	if(thr1) {
		err = pthread_join(thr1, NULL);
		if(err != 0) {
			fprintf(stderr, "Can't join to thread1: %s.\n", strerror(err));
		}
	}
	if(thr2) {
		err = pthread_join(thr2, NULL);
		if(err != 0) {
			fprintf(stderr, "Can't join to thread2: %s.\n", strerror(err));
		}
		
	}

	puts("End of process.");

	return 0;
}

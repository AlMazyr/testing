#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct Worker {
	char name[32];
	char position[32];
	int salary;
};

int main(int argc, char *argv[]) {

	if(argc != 2) {
		fprintf(stderr, "Err args. Usage %s <KEY_FILE>.\n", argv[0]);
		return -1;
	}

	void *shm_addr = 0;
	struct Worker *shm_worker = 0;

	// Creating key.
	key_t key = ftok(argv[1], 0);
	if(key == -1) {
		fprintf(stderr, "Err in ftok syscall: %s.\n", strerror(errno));
		return -1;
	}

	// Trying to get.
	int shm_id = shmget(key, sizeof(struct Worker), 0);
	if(shm_id < 0) {
		fprintf(stderr, "Can't get shared memory: %s.\n", strerror(errno));
		return -1;
	}
	
	// Adding shared memory segment to the process address space.
	shm_addr = shmat(shm_id, NULL, SHM_RDONLY);
	if(shm_addr == (void*)(-1)) {
		fprintf(stderr, "Err in shmat syscall: %s.\n", strerror(errno));
		return -1;
	}
	shm_worker = (struct Worker*)shm_addr;

	
	puts("Readed from shared memory:");
	printf("Name: %s.\nPosition: %s.\nSalary: %d.\n", shm_worker->name, shm_worker->position, shm_worker->salary);	
	
	shmdt(shm_addr);

	return 0;
}



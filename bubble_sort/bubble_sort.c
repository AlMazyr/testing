#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// o(n2)
void bubble_sort(int *arr, size_t n) {
	int temp = 0, i, j;
	for(i = 0; i < (n - 1); ++i) {
		for(j = 0; j < (n - i - 1); ++j) {
			if(arr[j] > arr[j + 1]) {
				//swap;
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
}


// common bubble sort
void bubble_sort_common(void* el, size_t e_sz, size_t n, int (*predicat)(void* prev, void* next)) {
	int temp = 0, i, j;
	char temp1[20];
	for(i = 0; i < (n - 1); ++i) {
		for(j = 0; j < (n - i - 1); ++j) {
			if (predicat(&(((char*)el)[j * e_sz]), &(((char*)el)[(j + 1) * e_sz])) == 1) {
				memcpy(temp1, &(((char*)el)[(j + 1) * e_sz]), e_sz);
				memcpy(&(((char*)el)[(j + 1) * e_sz]), &(((char*)el)[j * e_sz]), e_sz);
				memcpy(&(((char*)el)[j * e_sz]), temp1, e_sz); 
			}
		}
	}

	
}


int predicat_int(void *prev, void *next) {
	if(*((int*)prev) > *((int*)next))
		return 1;
	else
		return 0;
}

int predicat_double(void *prev, void *next) {
	if(*((double*)prev) > *((double*)next))
		return 1;
	else
		return 0;
}


int main(int argc, char *argv[]) {
	double test_arr[10] = {10.0, 4.2, 7.7, 2.1, 8.6, 9.1, 34.0, 1.1, 0.2, 4.3};
    int i = 0;
	
	//bubble_sort(test_arr, 10);
	for(i = 0; i < 10; ++i) {
		printf("[%f] ", test_arr[i]);
	}
	printf("\n");

	bubble_sort_common(test_arr, sizeof(test_arr[0]), 10, predicat_double);
	

	for(i = 0; i < 10; ++i) {
		printf("[%f] ", test_arr[i]);
	}
	printf("\n");

	return 0;
}

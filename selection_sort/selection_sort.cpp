#include <iostream>
#include <cstdio>

using namespace std;

void SelectionSort(int *arr, int n) {
	int min = 0, temp = 0;

	for(int i = 0; i < n - 1; ++i) {
		min = i;
		for(int j = i; j < n; ++j) {
			if(arr[j] < arr[min])
				min = j;
		}		
		if(min != i) {
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}


template<class T>
void SelectionSortCull(T *arr, int n) {
	int min = 0;
	
	for(int i = 0; i < n - 1; ++i) {
		min = i;
		for(int j = i; j < n; ++j) {
			if(arr[j] < arr[min])
				min = j;
		}		
		if(min != i) {
			swap(arr[i], arr[min]);
		}
	}
}

int main(int argc, char *argv[]) {

	int array[10] = {2, 5, 1, 0, 9, 7, 6, 4, 3, 8};

	for(int i = 0; i < 10; ++i) {
		printf("[%d] ", array[i]);
	}
	printf("\n");

	SelectionSortCull(array, 10);


	for(int i = 0; i < 10; ++i) {
		printf("[%d] ", array[i]);
	}
	printf("\n");

	return 0;
}

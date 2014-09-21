#include <iostream>
#include <cstdio>

using namespace std;


// Simple insetion sort.
void insert_sort(int *arr, int n) {
	int key = 0, i = 0, j = 0;
	bool insert = false;

	for(i = 1; i < n; ++i) {
		key = arr[i];

		for(j = i; j > 0; --j) {
			if(arr[j - 1] <= key)
				break;
			arr[j] = arr[j - 1];
			insert = true;
		}

		if(insert) {
			arr[j] = key;
			insert = false;
		}
	}
}

// c++ style
template<class T> 
void InsertionSortCull(T *arr, int n) {
	for(int i = 1; i < n; ++i) {
		for(int j = i; j && (arr[j - 1] > arr[j]); --j) {
			std::swap(arr[j], arr[j - 1]);
		}
	}
}

int main(int argc, char* argv[]) {

    int mass[10] = {0, 9, 4, 5, 1, 2, 8, 7, 3, 6};
    
    for(int i = 0; i < 10; ++i) {
        printf("[%d] ", mass[i]);
    }
    printf("\n");

//    insert_sort(mass, 10);
    InsertionSortCull(mass, 10);

    for(int i = 0; i < 10; ++i) {
        printf("[%d] ", mass[i]);
    }
    printf("\n");

}




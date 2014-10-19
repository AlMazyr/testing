#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

// c style simple merge sort 
void merge_sort(int *arr, int n) {

#ifdef DEBUG
	fprintf(stderr, "input array:\n");
	for(int i = 0; i < n; ++i) {
		fprintf(stderr, "[%d] ", arr[i]);
	}
	fprintf(stderr, "\n array length = %d.\n", n);
#endif

	if(n == 1)
		return;

	int *b = arr, *c = arr + (n / 2), b_len = n / 2, c_len = n - (n / 2);

#ifdef DEBUG	
	fprintf(stderr, "b length - %d, c length = %d.\n", b_len, c_len);
#endif

	merge_sort(b, b_len);
	merge_sort(c, c_len);

	// merging

	int i = 0, j = 0, k = 0, bcur = b[0], ccur = c[0];
	int *merged = new int[n];

	for(; i < n; ++i) {
		if(bcur < ccur) {
			merged[i] = bcur;
			j++;
			if(j < b_len)
				bcur = b[j];
			else
				bcur = 100000; // TODO
		} else {
			merged[i] = ccur;
			k++;
			if(k < c_len)
				ccur = c[k];
			else
				ccur = 100000; // TODO
		}
	}
#ifdef DEBUG
	fprintf(stderr, "Merged array is:");
	for(int i = 0; i < n; ++i) {
		fprintf(stderr, "[%d] ", merged[i]);
	}
#endif
	memcpy(arr, merged, n * sizeof(arr[0]));	
	delete[] merged;
}


int main(int argc, char *argv[]) {

	cout << "Testing merge sort.\n Please enter size of array:";
	int n;
	cin >> n;
	cout << endl;
	cout << "Please enter all values of array.\n";
	int *test = new int[n];
	for(int i = 0; i < n; ++i) {
		cin >> test[i];
	}

	merge_sort(test, n);

	cout << "Array after merging is: " << endl;
	for(int i = 0; i < n; ++i) {
		cout << "[" << test[i] << "] ";
	}
	cout << endl;

	return 0;
}

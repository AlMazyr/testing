#include <iostream>
#include <cstdio>

using namespace std;


// Insertion sort for int.
void insert_sort(int *arr, int n) {
    int key = 0, j = 0;
    bool insert = false;
    for(int i = 1; i < n; ++i) {
        key = arr[i];
        j = i;
        while(j > 0) {
            if(key >= arr[j - 1]) break;
            arr[j] = arr[j - 1];
            insert = true;
            j--;
        }
        if(insert) {
            arr[j] = key;
            insert = false;
        }
        
    }
}


int main(int argc, char* argv[]) {

    int mass[10] = {0, 9, 4, 5, 1, 2, 8, 7, 3, 6};
    
    for(int i = 0; i < 10; ++i) {
        printf("[%d] ", mass[i]);
    }
    printf("\n");

    insert_sort(mass, 10);

    for(int i = 0; i < 10; ++i) {
        printf("[%d] ", mass[i]);
    }
    printf("\n");

}




/*
 ============================================================================
 Name        : c_test_pattern.c
 Author      : algo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  printf("Input n:\n");
  int n;
  scanf("%d", &n);
  int array[n];
  printf("Sizeof array=%d", sizeof(array) / sizeof(n));


	return EXIT_SUCCESS;
}

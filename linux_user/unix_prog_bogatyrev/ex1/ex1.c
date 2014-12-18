#include <stdio.h>

int main(int argc, char *argv[]) {

    int a = 0, b = 0, c = 0;
    printf("a = %d, b = %d, c = %d.\n", a, b, c);
    a = b = 5;
    c = a++ + b;
    printf("a = %d, b = %d, c = %d.\n", a, b, c); // a = 6, b = 5, c = 10
    c = ++a + b;
    printf("a = %d, b = %d, c = %d.\n", a, b, c); // a = 7, b = 5, c = 12
    c = --a + b;
    printf("a = %d, b = %d, c = %d.\n", a, b, c); // a = 6, b = 5, c = 11
    c = a-- + b;
    printf("a = %d, b = %d, c = %d.\n", a, b, c); // a = 5, b = 5, c = 11


    return 0;
}

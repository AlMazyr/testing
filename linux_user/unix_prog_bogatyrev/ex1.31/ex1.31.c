#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int getch() {
    int ch;
    while((ch = getchar()) == 10);
    return ch;
}

int main(int argc, char *argv[]) {
    int x1 = 0, x2 = 0, average = 0, is_stop = 0, n = 0, fn = 0, ch = 0;

    puts("Please enter the limits:");
    scanf("%d", &x1);
    scanf("%d", &x2);
    n  = x2 - x1;

    while(!is_stop) {
        average = (x1 + x2) / 2;
        fn++;
        printf("Is %d the correct answer?\n", average);
        puts("If it's wrong number, enter '>' or '<', else '='.");
            switch(ch = getch()) {
                case '=':
                    is_stop = 1;
                    break;

                case '>':
                    x1 = average;
                    break;

                case '<':
                    x2 = average;
                    break;

                default:
                    printf("%d is wrong symbol. Use '=' if the number is correct, or '>', '<' if it's not.\n", ch);
                    break;
            }   

    }

    printf("Search is finished, n = %d, f(n) = %d\n", n, fn);

    return EXIT_SUCCESS;
}

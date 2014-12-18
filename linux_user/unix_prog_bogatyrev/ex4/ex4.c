#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Err args. Usage %s <PYRAMID_HEIGHT>.\n", argv[0]);
        return EXIT_FAILURE;
    }

    int i = 0, j = 0, height = atoi(argv[1]), length = height * 2 - 1, zi_count = 0, pi_count = 0;


    // Printing pyramid
    for(; i < height; ++i) {
        zi_count = i * 2 + 1; // count of stars
        pi_count = height - i - 1;  // count of spaсes
        for(j = 0; j < length; ++j) {
            if((j >= pi_count) && (j <= (zi_count + pi_count - 1))) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');

    }

    return EXIT_SUCCESS;
}

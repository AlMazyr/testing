#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {


    // returning ascii code in hex and oct
    int c = 0;

    while((c = getchar()) != EOF) {
        if(c != 0xa)
            printf("hex = %x, dec = %d, oct = %o.\n", c, c, c);
    }


    return EXIT_SUCCESS;
}

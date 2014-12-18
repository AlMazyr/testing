#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        fprintf(stderr, "Err arguments. Usage %s <CATHETUS SIZE>.\n", argv[0]);
        return EXIT_FAILURE;
    }

    int i = 0, cathetus_sz = atoi(argv[1]);
    char *buf = (char*)malloc(sizeof(char) * cathetus_sz);

    for(; i < cathetus_sz; ++i) {
        buf[i] = '*';
        puts(buf);
    }

    free(buf);
    return EXIT_SUCCESS;
}

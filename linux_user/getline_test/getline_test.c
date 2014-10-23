#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("text_file", "r");
    if(fp == NULL)
        return EXIT_FAILURE;
    
    while((read = getline(&line, &len, fp)) != -1) {
        printf("Retrived line of length %zu :\n", read);
        printf("%s", line);
    }
    free(line);
    
    return EXIT_SUCCESS;
}

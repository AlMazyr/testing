#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]) {
    
    int r_count = 0, w_count = 0, fd1 = 0, fd2 = 0;
    char buff[BUFSIZ];

    if(argc != 3) {
        fprintf(stderr, "Err parameters. Usage %s <FILE1> <FILE2>.\n", argv[0]);
        return EXIT_FAILURE;
    }

    if((fd1 = open(argv[1], O_RDONLY)) == -1 ) {
       fprintf(stderr, "Cannot read file <%s>, err: %s.\n", argv[1], strerror(errno));
       return EXIT_FAILURE;
    }
    if((fd2 = open(argv[2], O_WRONLY)) == -1 ) {
       fprintf(stderr, "Cannot read file <%s>, err: %s.\n", argv[2], strerror(errno));
       return EXIT_FAILURE;
    }

    while((r_count = read(fd1, buff, sizeof(buff))) > 0) {
        w_count = write(fd2, buff, r_count);
        if(w_count != r_count) {
            fprintf(stderr, "Read error: %s.\n", strerror(errno));
            break;
        }

    }


    close(fd1);
    close(fd2);

    return EXIT_SUCCESS;
}

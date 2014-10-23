#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <alloca.h>

extern void afunc(void);

int bss_var; // must be in bss segment
int data_var = 42;  //must be in data segment

extern char **environ;

int main(int argc, char *argv[]) {

    char *p, *b, *nb;

    printf("Text Locations:\n");

    printf("\tAddress of main: %p\n", main);
    printf("\tAddress of afunc: %p\n", afunc);

    printf("Main arguments:\n");
    printf("\tAddress of argc: %p\n", &argc);
    printf("\tAddress of string in argv: %p\n", &argv[0][0]);
    printf("\tAddress of first environ string: %p\n", &environ[0][0]);

    printf("Stack Locations. \n");
    afunc();

    p = (char *)alloca(32);

    if(p != NULL) {
        printf("\tStart of alloca()'ed array: %p\n", p);
        printf("\tEnd of alloca()'ed array: %p\n", p + 31);
    }

    printf("Data Locations:\n");
    printf("\tAddress of data_var = %p\n", &data_var);

    printf("BSS Locations:\n");
    printf("\tAddress of bss_var = %p\n", &bss_var);

    b = sbrk((ptrdiff_t)32);
    nb = sbrk((ptrdiff_t)0);

    printf("Heap Locations:\n");
    printf("\tInitial end of heap: %p\n", b);
    printf("\tNew end of heap: %p\n", nb);

    b = sbrk((ptrdiff_t)-16);
    nb = sbrk((ptrdiff_t)0);
    printf("\tFinal end of heap: %p\n", nb);

   
    return EXIT_SUCCESS;
}

void afunc(void) {
    static int level = 0;
    auto int stack_var;

    if(++level == 3)
        return;

    printf("\tStack level %d: address of stack_var: %p\n", level, &stack_var);
    afunc();
}

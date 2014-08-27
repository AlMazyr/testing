#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

// printf scnaf

int main(int argc, char *argv[]) {
    float h = 0, w = 0;
    puts("Enter h, w:\n");    
    scanf("%f %f", &h, &w);
    const char* units = "см";
    printf("Height = %5.3f(%s), width = %5.3f(%s)\n", h, units, w, units);
}


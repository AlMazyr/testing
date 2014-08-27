#include <stdio.h>
#include <stdlib.h>

// Calculating sum of numeric line: 1, -1/3, +1/5, -1/7, +1/9... .

int main() {

    const double pi = 3.1416;
    const double pi_4 = pi / 4;

    int i = 0, n = 0;
    double sum = 0;

    while(1) {
        puts("Enter the number of members.\n");
        
        sum = 0;

        scanf("%d", &n);
        for(i = 0; i < n; ++i) {
            sum += (1.0 / ((2.0 * i + 1) * (((i % 2) ? -1 : 1))));
        }
        printf("\n");
        
        printf("Sum = %5.3f, pi/4 = %5.3f\n", sum, pi_4);
    }

}

#include <stdio.h>

int main(void) {
    int x;
    scanf("%d", &x);
    int square_x = x * x;  // compute square of x
    printf("%d\n", square_x * x);  // compute cube of x using square_x
    return 0;
}
#include <stdio.h>

int main(void) {
    int x;
    scanf("%d", &x);
    x *= x;   /* Squaring x */
    x *= x;   /* And then cubing it */
    printf("%d\n", x);
    return 0;
}
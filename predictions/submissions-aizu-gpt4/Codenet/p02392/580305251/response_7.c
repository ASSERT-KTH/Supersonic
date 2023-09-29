#include <stdio.h>

int main(void) {
    int a, b, c;
    if(scanf("%d %d %d", &a, &b, &c) == 3 && a < b && b < c && a >= 0 && c <= 100) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
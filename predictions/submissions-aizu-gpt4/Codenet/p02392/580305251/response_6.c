#include <stdio.h>

int main(void) {
    int a, b, c;
    if(scanf("%d %d %d", &a, &b, &c) == 3 && a >= 0 && a <= 100 && b >= 0 && b <= 100 && c >= 0 && c <= 100) {
        puts((a < b && b < c) ? "Yes" : "No");
    }
    return 0;
}
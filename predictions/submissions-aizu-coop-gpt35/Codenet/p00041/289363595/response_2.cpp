#include <stdio.h>

int main() {
    int a, b, c, d;

    while (1) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == 0) {
            break;
        }
        
        printf("%d+%d+%d+%d\n", a, b, c, d);
    }

    return 0;
}
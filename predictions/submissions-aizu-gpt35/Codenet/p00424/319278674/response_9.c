#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char t[1000] = {0}; // initialize the array to all zeros
    while (scanf("%d", &n) == 1) {
        memset(t, 0, sizeof(t)); // use memset to clear the array
        while (n--) {
            int i;
            char c1, c2;
            scanf("%d", &i);
            scanf(" %c %c", &c1, &c2);
            t[i] = c2;
        }
        scanf("%d", &n);
        while (n--) {
            int i;
            scanf("%d", &i);
            putchar(!t[i] ? ' ' : t[i]);
        }
        putchar('\n');
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int n, t[MAX_SIZE];
int main() {
    int i;
    while (scanf("%d", &n) != EOF) {
        memset(t, 0, sizeof(t));
        while(n--) {
            scanf(" %c", &i);
            t[i] = 1;
        }
        scanf("%d", &n);
        while(n--) {
            scanf(" %c", &i);
            putchar(!t[i] * i + t[i]);
        }
        putchar('\n');
    }
    return 0;
}
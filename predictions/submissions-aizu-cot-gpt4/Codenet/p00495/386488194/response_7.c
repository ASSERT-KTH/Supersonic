#include <stdio.h>

#define MAX_SIZE 5004
#define FORMAT "%d\n"

int c[MAX_SIZE], d[MAX_SIZE], m = 0, t = 0, u = 0, i = 0;
char* f = FORMAT;

int main() {
    scanf("%d%*d", c);
    while (i < *c) {
        scanf(f, ++i + c);
    }
    int x = 0;
    while (~scanf(f, &x)) {
        for (u = i = t = 0; i++ < *c;) {
            if (m < u) {
                m = u;
                d[i] = m;
            } else {
                d[i] = u;
            }
            if (x - c[i] != 0) {
                u = u;
            } else {
                u = t + 1;
            }
        }
    }
    printf(f, m);
    return 0;
}
#include <stdio.h>

int main() {
    int a[4];
    char output[110004];

    for (int i = 0; i < 110000; ++i) {
        output[i] = '(';
    }

    while (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]), a[0]) {
        sprintf(output + 110000, "%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
        fputs(output, stdout);
    }
}
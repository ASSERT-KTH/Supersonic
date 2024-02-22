#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n;
    int upBound = 1000000;
    int sqrtBound = (int)sqrt(upBound);

    int* num = (int*)malloc(sizeof(int) * upBound);
    if (num == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    for (i = 0; i < upBound; i++) {
        num[i] = 1;
    }
    num[0] = num[1] = 0;

    for (i = 2; i <= sqrtBound; i++) {
        if (num[i] == 1) {
            for (j = i * i; j < upBound; j += i)
                num[j] = 0;
        }
    }

    for (i = 1; i < upBound - 1; i++) {
        num[i + 1] += num[i];
    }

    while (scanf("%d", &n) != EOF) {
        printf("%d\n", num[n]);
    }

    free(num);
    return 0;
}
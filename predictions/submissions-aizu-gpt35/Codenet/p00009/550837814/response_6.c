#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NUM 1000000

int main() {
    int i, j, n;
    bool *num = calloc(MAX_NUM, sizeof(bool));
    int *prefix_sum = calloc(MAX_NUM + 1, sizeof(int));

    for (i = 2; i < sqrt(MAX_NUM); i++) {
        if (!num[i]) {
            for (j = i * i; j < MAX_NUM; j += i)
                num[j] = true;
        }
    }

    for (i = 2; i <= MAX_NUM; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + !num[i];
    }

    while (scanf("%d", &n) != EOF) {
        printf("%d\n", prefix_sum[n]);
    }

    free(num);
    free(prefix_sum);

    return 0;
}
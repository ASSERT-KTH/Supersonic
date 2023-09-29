#include <math.h>
#include <stdio.h>

#define MAX_NUM 1000000

int main() {
    int i, j;
    int n;
    int num[MAX_NUM];
    for (i = 0; i < MAX_NUM; i++) {
        num[i] = 1;
    }
    num[0] = num[1] = 0;
    for (i = 2; i <= sqrt(MAX_NUM); i++) {
        if (num[i] == 1) {
            for (j = i * i; j < MAX_NUM; j += i)
                num[j] = 0;
        }
    }
    for (i = 1; i < MAX_NUM - 1; i++) {
        num[i + 1] += num[i];
    }
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", num[n]);
    }
    return 0;
}
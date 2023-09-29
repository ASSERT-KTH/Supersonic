#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main() {
    int i, j, n;
    char *num = calloc(MAX, sizeof(char));
    int *prime_sum = calloc(MAX, sizeof(int));
    
    for (i = 2; i < sqrt(MAX); i++) {
        if (num[i] == 0) {
            for (j = i * i; j < MAX; j += i) {
                num[j] = 1;
            }
        }
    }
    
    for (i = 2; i < MAX; i++) {
        prime_sum[i] = prime_sum[i-1] + !num[i];
    }
    
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", prime_sum[n]);
    }
    
    free(num);
    free(prime_sum);
    return 0;
}
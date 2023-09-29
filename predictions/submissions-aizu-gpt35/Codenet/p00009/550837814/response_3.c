#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 1000000
bool prime[MAX];
int count[MAX];
int main() {
    int i, j, n;
    for (i = 2; i < MAX; i++) {
        prime[i] = true;
    }
    for (i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (j = i * i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
    for (i = 2; i < MAX; i++) {
        count[i] = count[i - 1] + prime[i];
    }
    while (scanf("%d", &n) == 1) {
        printf("%d\n", count[n]);
    }
    return 0;
}
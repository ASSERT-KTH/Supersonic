#include <math.h>
#include <stdio.h>

int main() {
    int i, j;
    int n;
    int num[1000001] = {0}; // initialize array to all 0's
    num[0] = 0;
    num[1] = 0;
    for (i = 2; i <= sqrt(1000000); i++) {
        if (num[i] == 0) {
            for (j = i * i; j <= 1000000; j += i)
                num[j] = 1;
        }
    }
    for (i = 1; i <= 1000000; i++) {
        num[i] += num[i - 1];
    }
    while (scanf("%d", &n) != EOF) { // use while loop instead of for loop
        printf("%d\n", num[n]);
    }
    return 0;
}
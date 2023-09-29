#include <cmath>
#include <cstdio>

const int N = 1e6;
int num[N];

int main() {
    int n, i, j;
    num[0] = num[1] = 0;
    for (i = 2; i < N; i++) {
        num[i] = 1;
    }
    int lim = sqrt(N);
    for (i = 2; i <= lim; i++) {
        if (num[i]) {
            for (j = i * i; j < N; j += i) {
                num[j] = 0;
            }
        }
    }
    for (i = 1; i < N; i++) {
        num[i] += num[i - 1];
    }
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", num[n]);
    }
    return 0;
}
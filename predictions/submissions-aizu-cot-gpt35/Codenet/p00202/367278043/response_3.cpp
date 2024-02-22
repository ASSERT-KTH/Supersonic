#include <stdio.h>

const int MAX_N = 30;
const int MAX_X = 1000000;

bool prime[MAX_X + 1];
int n, x, a[MAX_N], dp[MAX_X + 1];

int main() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= MAX_X; i++) {
        prime[i] = true;
    }

    for (int i = 2; i * i <= MAX_X; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX_X; j += i) {
                prime[j] = false;
            }
        }
    }

    while (scanf("%d%d", &n, &x), n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i <= x; i++) {
            dp[i] = false;
        }
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = a[i]; j <= x; j++) {
                if (dp[j - a[i]]) {
                    dp[j] = true;
                }
            }
        }

        for (int i = x; i >= 0; i--) {
            if (dp[i]) {
                printf(i ? "%d\n" : "NA\n", i);
                break;
            }
        }
    }

    return 0;
}
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAX_N = 1000001;
bool dp[MAX_N], prime[MAX_N];
int a[30];

void sieve() {
    fill(prime, prime + MAX_N, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= MAX_N; ++i) {
        if (prime[i]) {
            for (int j = i*i; j <= MAX_N; j += i)
                prime[j] = false;
        }
    }
}

int main() {
    sieve();
    int n, x;
    while (scanf("%d%d", &n, &x), n) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        fill(dp, dp + x + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++)
            for (int j = a[i]; j <= x; j++)
                dp[j] = dp[j] || dp[j - a[i]];

        for (int i = x; i >= 0; i--) {
            if (dp[i] && prime[i]) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
#include <algorithm>
#include <stdio.h>
using namespace std;
int n, x, a[30];
bool dp[1000001], prime[1000001];
void sieve() {
    fill(prime, prime+1000001, true);
    prime[0] = prime[1] = false;
    for (int p=2; p*p<=1000000; p++) {
        if (prime[p]) {
            for (int i=p*p; i<=1000000; i += p)
                prime[i] = false;
        }
    }
}
int main() {
    sieve();
    while (scanf("%d%d", &n, &x), n) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        fill(dp, dp+x+1, false);
        dp[0] = true;
        for (int i = 1; i <= x; i++) {
            for (int j = 0; j < n && a[j] <= i; j++) {
                if (dp[i - a[j]]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        for (int i = x; i >= 0; i--) {
            if (dp[i] && prime[i]) {
                printf("%d\n", i);
                break;
            }
            else if (i == 0)
                printf("NA\n");
        }
    }
}
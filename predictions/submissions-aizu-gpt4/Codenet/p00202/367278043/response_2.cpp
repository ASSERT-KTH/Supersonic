#include <algorithm>
#include <stdio.h>
using namespace std;
constexpr int MAX = 1000001;
int n, x, a[30];
bool dp[MAX], prime[MAX];

void sieve() {
  fill(prime, prime + MAX, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (prime[i]) {
      for (int j = i * i; j < MAX; j += i)
        prime[j] = false;
    }
  }
}

int main() {
  sieve();
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    fill(dp, dp + x + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
      for (int j = x; j >= a[i]; j--)
        dp[j] = dp[j] || dp[j - a[i]];
    for (int i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
}
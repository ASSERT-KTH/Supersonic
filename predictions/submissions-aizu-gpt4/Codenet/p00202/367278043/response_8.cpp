#include <algorithm>
#include <stdio.h>

int n, x, a[30];
bool dp[1000001], prime[1000001];

void calculatePrimes() {
  prime[0] = prime[1] = false;
  prime[2] = true;
  for (int i = 3; i <= 1000000; i += 2) prime[i] = true;
  for (int i = 3; i * i <= 1000000; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j <= 1000000; j += i * 2) {
        prime[j] = false;
      }
    }
  }
}

int main() {
  calculatePrimes();
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    std::sort(a, a + n);
    std::fill_n(dp, x + 1, false);
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
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
}
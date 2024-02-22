#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, x;
  int a[30];
  bool dp[1000001], prime[1000001];

  prime[0] = true, prime[2] = true;
  for (int i = 3; i <= 1000000; i += 2)
    prime[i] = true;
  for (int i = 3; i <= 1000; i++) {
    if (!prime[i])
      continue;
    for (int j = i, product = i*j; product <= 1000000; j += 2, product = i*j)
      prime[product] = false;
  }

  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    memset(dp, false, sizeof(dp));
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
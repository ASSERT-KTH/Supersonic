#include <algorithm>
#include <stdio.h>
#include <bitset>
using namespace std;
int n, x, a[30];
bitset<1000001> dp, prime;
int main() {
  prime[0] = prime[1] = true;
  for (int i = 3; i <= 1000000; i += 2)
    prime[i] = true;
  for (int i = 3; i <= 1000; i += 2) {
    if (prime[i])
      for (int j = i * i; j <= 1000000; j += i)
        prime[j] = false;
  }
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    dp.reset();
    dp[0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = a[i]; j <= x; j++) {
        dp[j] = dp[j] || dp[j - a[i]];
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
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN = 30, MAXX = 1e6 + 1;
int n, x, a[MAXN];
bool dp[MAXX], prime[MAXX];
int main() {
  prime[0] = true, prime[2] = true;
  for (int i = 3; i <= MAXX - 1; i += 2)
    prime[i] = true;
  for (int i = 3; i <= 1000; i += 2) {
    if (!prime[i])
      continue;
    for (int j = i; i * j <= MAXX - 1; j += 2)
      prime[i * j] = false;
  }
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i <= x; i++)
      dp[i] = false;
    dp[0] = true;
    for (int i = 1; i <= x; i++) {
      if (!dp[i]) {
        for (int j = 0; j < n && a[j] <= i; j++) {
          dp[i] |= dp[i - a[j]];
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
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_N = 30;
const int MAX_X = 1e6;
bool dp[MAX_X + 1], prime[MAX_X + 1];
int n, x, a[MAX_N];
int main() {
  prime[0] = true, prime[2] = true;
  for (int i = 3; i <= MAX_X; i += 2)
    prime[i] = true;
  for (int i = 3; i * i <= MAX_X; i += 2) {
    if (!prime[i])
      continue;
    for (int j = i * i; j <= MAX_X; j += 2 * i)
      prime[j] = false;
  }
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i <= x; i++)
      dp[i] = false;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = a[i]; j <= x; j++) {
        dp[j] |= dp[j - a[i]];
      }
    }
    for (int i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
  return 0;
}
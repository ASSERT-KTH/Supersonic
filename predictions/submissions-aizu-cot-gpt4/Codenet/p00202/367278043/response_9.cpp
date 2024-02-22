#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int n, x;
vector<int> a;
bool dp[1000001], prime[1000001];
int main() {
  prime[0] = prime[1] = false, prime[2] = true;
  for (int i = 3; i <= 1000000; i += 2)
    prime[i] = true;
  for (int i = 3; i * i <= 1000000; i += 2) {
    if (!prime[i])
      continue;
    for (int j = i * i; j <= 1000000; j += 2 * i)
      prime[j] = false;
  }
  while (scanf("%d%d", &n, &x), n) {
    a.resize(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    fill(dp, dp + x + 1, false);
    dp[0] = true;
    for (int i = 1; i <= x; i++) {
      for (int j = 0; j < n && i >= a[j]; j++) {
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
    a.clear();
  }
}
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int n, x, a[30];
bool dp[1000001], prime[1000001];

void sieve() {
  prime[0] = prime[1] = false;
  prime[2] = true;
  for (int i = 3; i <= 1000000; i += 2)
    prime[i] = true;
  int sq = (int)sqrt(1000000);
  for (int i = 3; i <= sq; i++) {
    if (!prime[i])
      continue;
    for (int j = i * i; j <= 1000000; j += i * 2)
      prime[j] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();

  while (cin >> n >> x, n) {
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);

    fill(dp, dp + x + 1, false);
    dp[0] = true;

    for (int j = 0; j < n; j++)
      for (int i = a[j]; i <= x; i++)
        dp[i] = dp[i] || dp[i - a[j]];

    for (int i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        cout << (i ? to_string(i) : "NA") << "\n";
        break;
      }
    }
  }
}
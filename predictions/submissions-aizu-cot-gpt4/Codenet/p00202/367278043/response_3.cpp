#include <iostream>
using namespace std;
int n, x, a[30];
bool dp[1000001], prime[1000001];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  prime[0] = prime[1] = false;
  for (int i = 2; i <= 1000000; i++) prime[i] = true;
  for (int i = 2; i*i <= 1000000; i++) {
    if (!prime[i]) continue;
    for (int j = i*i; j <= 1000000; j += i) prime[j] = false;
  }

  dp[0] = true;
  while (cin >> n >> x, n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= x; i++) dp[i] = false;
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
        cout << (i ? to_string(i) : "NA") << "\n";
        break;
      }
    }
  }
  return 0;
}
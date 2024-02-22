#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, x;
vector<int> a(30);
vector<bool> dp(1000001), prime(1000001);

void generate_primes() {
  prime[0] = true, prime[2] = true;
  for (int i = 3; i <= 1000000; i += 2)
    prime[i] = true;
  for (int i = 3; i <= 1000; i++) {
    if (!prime[i])
      continue;
    for (int j = i; i * j <= 1000000; j += 2)
      prime[i * j] = false;
  }
}

int main() {
  generate_primes();
  while (cin >> n >> x, n) {
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.begin() + n);
    if (x >= dp.size()) dp.resize(x+1);
    fill(dp.begin(), dp.begin() + x + 1, false);
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
        cout << (i ? to_string(i) : "NA") << '\n';
        break;
      }
    }
  }
}
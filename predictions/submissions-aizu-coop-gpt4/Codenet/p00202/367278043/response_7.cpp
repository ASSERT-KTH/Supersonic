#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, x;
vector<int> a;
vector<int> dp;
vector<bool> prime;

void genPrimes(int max) {
  prime[2] = true;
  for (int i = 3; i <= max; i += 2)
    prime[i] = true;
  for (int i = 3; i * i <= max; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j <= max; j += i * 2)
        prime[j] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n >> x, n) {
    a.resize(n);
    dp.clear();
    dp.resize(x + 1);
    prime.clear();
    prime.resize(x + 1);
    
    genPrimes(x);  // Generate primes up to x
    
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());

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
        cout << (i != 0 ? to_string(i) : "NA") << "\n";
        break;
      }
    }
  }
}
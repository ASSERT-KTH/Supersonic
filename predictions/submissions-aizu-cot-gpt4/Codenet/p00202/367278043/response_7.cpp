#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int n, x, a[30];
bool dp[1000001] = {true}, prime[1000001] = {false};
prime[2] = true;

int main() {
  for (int i = 3; i <= 1000000; i += 2)
    prime[i] = true;
  for (int i = 3; i * i <= 1000000; i++) {
    if (!prime[i])
      continue;
    for (int j = i * i; j <= 1000000; j += 2 * i)
      prime[j] = false;
  }
  while (cin >> n >> x, n) {
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
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
}
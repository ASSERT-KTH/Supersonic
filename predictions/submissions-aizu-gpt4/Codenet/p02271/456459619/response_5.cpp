#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t, n;
  cin >> n;
  vector<int> N(n);
  for (int &num : N) {
    cin >> num;
  }
  cin >> t;
  while (t--) {
    int p;
    cin >> p;
    vector<bool> dp(p + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = p; j >= N[i]; j--) {
        dp[j] |= dp[j - N[i]];
      }
    }
    cout << (dp[p] ? "yes" : "no") << endl;
  }
}
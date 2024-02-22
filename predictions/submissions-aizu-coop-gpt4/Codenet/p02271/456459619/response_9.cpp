#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
  int n, t;
  cin >> n;
  vector<int> N(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  cin >> t;
  vector<int> dp(20000, false);
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = dp.size() - 1; j >= N[i]; j--) {
      dp[j] = dp[j] || dp[j - N[i]];
    }
  }
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    if (dp[p]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, t;
  cin >> n;
  vector<int> N(n);
  for (int& num : N) {
    cin >> num;
  }
  cin >> t;
  while(t--) {
    int p;
    cin >> p;
    vector<bool> dp(p+1, false);
    dp[0] = true;
    for (int& num : N) {
      for (int j = p; j >= num; --j) {
        dp[j] = dp[j] || dp[j - num];
      }
    }
    if (dp[p]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
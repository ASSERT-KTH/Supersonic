#include <iostream>
#include <vector>
using namespace std;

vector<int> N;
int n;

bool solve(int sum) {
  vector<bool> dp(sum + 1, false);
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = sum; j >= N[i]; j--) {
      dp[j] = dp[j] || dp[j - N[i]];
    }
  }
  return dp[sum];
}

int main() {
  int t;
  cin >> n;
  N.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    if (solve(p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
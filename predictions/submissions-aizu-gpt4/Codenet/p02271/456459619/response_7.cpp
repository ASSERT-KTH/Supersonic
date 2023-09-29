#include <iostream>
#include <vector>
using namespace std;

vector<int> N;
int n;

bool solve(vector<vector<int>>& dp, int i, int m) {
  if (m == 0) return true;
  if (i == n) return false;
  if (dp[i][m] != -1) return dp[i][m];
  return dp[i][m] = solve(dp, i + 1, m - N[i]) || solve(dp, i + 1, m);
}

int main() {
  int t;
  cin >> n;
  N = vector<int>(n);
  for (auto& num : N) cin >> num;
  cin >> t;

  while (t--) {
    int p;
    cin >> p;
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, -1));
    cout << (solve(dp, 0, p) ? "yes" : "no") << '\n';
  }
}
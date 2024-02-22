#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool solve(const vector<int>& N, int i, int m, vector<vector<int>>& memo) {
  if (m == 0) {
    return true;
  }
  if (i == N.size() || m < 0) {
    return false;
  }
  if (memo[i][m] != -1) {
    return memo[i][m];
  }
  bool result = solve(N, i + 1, m - N[i], memo) || solve(N, i + 1, m, memo);
  memo[i][m] = result ? 1 : 0;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> N(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    vector<vector<int>> memo(n, vector<int>(p + 1, -1));
    if (solve(N, 0, p, memo)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
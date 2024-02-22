#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> N;
int n;
vector<vector<int>> dp;

bool solve(int i, int m) {
  if (i == n) {
    return m == 0;
  }

  if (dp[i][m] != -1) {
    return dp[i][m];
  }

  bool result = solve(i + 1, m - N[i]) || solve(i + 1, m);
  dp[i][m] = result;
  return result;
}

int main() {
  int t;
  scanf("%d", &n);
  N.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  scanf("%d", &t);

  dp.resize(n + 1, vector<int>(t + 1, -1));

  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (solve(0, p)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}
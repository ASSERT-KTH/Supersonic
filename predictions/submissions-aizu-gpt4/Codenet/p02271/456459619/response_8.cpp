#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> N;
int n;

bool solve(int i, int m, vector<vector<int>>& dp) {
  if (dp[i][m+20000] != -1) {
    return dp[i][m+20000];
  }
  if (i == n) {
    return dp[i][m+20000] = (m == 0);
  }
  return dp[i][m+20000] = solve(i + 1, m - N[i], dp) || solve(i + 1, m, dp);
}

int main() {
  int t;
  scanf("%d", &n);
  N = vector<int>(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    vector<vector<int>> dp(n+1, vector<int>(40001, -1));
    if (solve(0, p, dp)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 101;
int n, m;
double dp[MAXN][MAXN];
double t[MAXN][MAXN];

double solve(int times, int prev) {
  if (dp[times][prev] >= 0)
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = 1;
  double tmp = -1;
  for (int i = 0; i < n; i++) {
    if (times == 0) {
      tmp = max(tmp, solve(times + 1, i) * 1);
    } else {
      tmp = max(tmp, solve(times + 1, i) * t[prev][i]);
    }
  }
  return dp[times][prev] = tmp;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    printf("%.2lf\n", round(solve(0, 0) * 100) / 100);
  }
}
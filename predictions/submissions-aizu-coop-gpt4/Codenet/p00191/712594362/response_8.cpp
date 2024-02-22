#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<vector<double>> dp(101, vector<double>(101));
vector<vector<double>> t(101, vector<double>(101));

double solve(int times, int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = 1;
  double tmp = -1;
  for (int i = 0; i < n; i++) {
    if (times == 0) {
      tmp = max(tmp, solve(times + 1, i));
    } else {
      tmp = max(tmp, solve(times + 1, i) * t[prev][i]);
    }
  }
  return dp[times][prev] = tmp;
}

int main(void) {
  while (scanf("%d %d", &n, &m) != EOF) {
    if (!(n | m))
      break;
    for (int i = 0; i < 101; i++) {
      fill(dp[i].begin(), dp[i].end(), -1);
    }
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%lf", &t[i][j]);
      }
    }
    retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
  return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 101;
int n, m;
double dp[MAX_N][MAX_N];
double t[MAX_N][MAX_N];

double solve(int times, int prev) {
  if (dp[times][prev] != -1)
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
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    double retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}
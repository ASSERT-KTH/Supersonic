#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
double dp[101][101];
double t[101][101];

double solve(unsigned short int times, unsigned short int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = 1;
  double max_val = -1.0, tmp;
  for (unsigned short int i = 0; i < n; i++) {
    if (times == 0) {
      tmp = solve(times + 1, i);
    } else {
      tmp = solve(times + 1, i) * t[prev][i];
    }
    max_val = max(max_val, tmp);
  }
  return dp[times][prev] = max_val;
}

int main(void) {
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    fill((double *)dp, (double *)dp + 101 * 101, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    double retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}
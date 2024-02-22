#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, m;

vector<double> dp(101 * 101, -1);
vector<vector<double>> t(101, vector<double>(101, 0));

double solve(int times, int prev) {
  if (dp[times * 101 + prev] != -1)
    return dp[times * 101 + prev];
  if (times == m)
    return dp[times * 101 + prev] = 1;
  double tmp = -1;
  for (int i = 0; i < n; i++) {
    // Store the result of solve function in a variable to avoid redundant computation
    double res = solve(times + 1, i);
    if (times == 0) {
      tmp = max(tmp, res);
    } else {
      tmp = max(tmp, res * t[prev][i]);
    }
  }
  return dp[times * 101 + prev] = tmp;
}

int main(void) {
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    fill(dp.begin(), dp.end(), -1);
    double retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}
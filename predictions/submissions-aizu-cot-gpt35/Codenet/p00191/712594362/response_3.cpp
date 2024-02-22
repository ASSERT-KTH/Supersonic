#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
bool dp[101][101];
float t[101][101];

float solve(int times, int prev) {
  if (dp[times][prev])
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = true;
  float tmp = 0.0;
  for (int i = 0; i < n; i++) {
    if (times == 0) {
      tmp = std::max(tmp, solve(times + 1, i) * 1.0);
    } else {
      tmp = std::max(tmp, solve(times + 1, i) * t[prev][i]);
    }
  }
  return dp[times][prev] = tmp;
}

int main(void) {
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    std::fill_n((bool *)dp, 101 * 101, false);
    int ret;
    float retd;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    retd = solve(0, 0) * 100;
    printf("%.2f\n", round(retd) / 100);
  }
}
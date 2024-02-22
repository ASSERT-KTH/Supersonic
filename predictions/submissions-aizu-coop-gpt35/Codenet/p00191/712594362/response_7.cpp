#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n, m;
float dp[101][101]; // Use float instead of double for dp array
double t[101][101];

float solve(int times, int prev) {
  if (dp[times][prev] != -1.0f)
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = 1.0f;
  float tmp = -1.0f;
  for (int i = 0; i < n; i++) {
    if (times == 0) {
      tmp = max(tmp, solve(times + 1, i) * 1.0f);
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
    fill((float *)dp, (float *)dp + 101 * 101, -1.0f);

    int ret;
    float retd; // Use float instead of double for retd
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }

    retd = solve(0, 0) * 100.0f;
    printf("%d.%02d\n", (int)retd, (int)(retd * 100) % 100);
  }
}
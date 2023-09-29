#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
double dp[101][101];
double t[101][101];

double solve(int times, int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];

  double tmp = (times == m) ? 1 : -1;
  for (int i = 0; i < n; i++) {
    if(tmp != 1){
      tmp = max(tmp, solve(times + 1, i) * ((times == 0) ? 1 : t[prev][i]));
    }
  }
  return dp[times][prev] = tmp;
}

int main(void) {
  while (cin >> n >> m && (n | m)) {
    fill_n((double *)dp, 101*101, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }
    printf("%.2lf\n", round(solve(0, 0) * 100) / 100);
  }
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
using namespace std;
int n, m;
double dp[101][101];
double t[101][101];
double solve(int times, int prev) {
  if (dp[times][prev] != -1)
    return dp[times][prev];
  if (times == m)
    return dp[times][prev] = 1;
  double tmp = -1;
  if (times == 0) {
    tmp = max(tmp, solve(times + 1, 0));
  } else {
    for (int i = 0; i < n; i++) {
      tmp = max(tmp, solve(times + 1, i) * t[prev][i]);
    }
  }
  return dp[times][prev] = tmp;
}
int main(void) {
  while (cin >> n >> m) {
    if (!(n | m))
      break;
    fill((double *)dp, (double *)dp + 101 * 101, -1);
    double retd;
    std::copy(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), t[0]);
    retd = solve(0, 0) * 100;
    printf("%.2lf\n", round(retd) / 100);
  }
}
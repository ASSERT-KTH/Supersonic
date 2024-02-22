#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int n, m;
double dp[101][101];
bool visited[101][101];
double t[101][101];

double solve() {
  for (int times = m; times >= 0; --times) {
    for (int prev = 0; prev < n; ++prev) {
      if (times == m) {
        dp[times][prev] = 1;
        visited[times][prev] = true;
      } else if (!visited[times][prev]) {
        double tmp = -1;
        for (int i = 0; i < n; ++i) {
          tmp = max(tmp, dp[times + 1][i] * ((times == 0) ? 1 : t[prev][i]));
        }
        dp[times][prev] = tmp;
        visited[times][prev] = true;
      }
    }
  }
  return dp[0][0] * 100;
}

int main(void) {
  while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%lf", &t[i][j]);
      }
    }
    printf("%.2lf\n", round(solve()) / 100);
  }
  return 0;
}
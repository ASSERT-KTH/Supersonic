#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

bool solve(int i, int m, int* N, int** dp) {
  if (m == 0) {
    return true;
  }
  if (i < 0) {
    return false;
  }
  if (dp[i][m] != -1) {
    return dp[i][m];
  }
  bool res = solve(i - 1, m - N[i], N, dp) || solve(i - 1, m, N, dp);
  dp[i][m] = res;
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  int* N = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int p;
    scanf("%d", &p);
    int** dp = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
      dp[i] = (int*)calloc(p + 1, sizeof(int));
      memset(dp[i], -1, (p + 1) * sizeof(int));
    }
    if (solve(n - 1, p, N, dp)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
    for (int i = 0; i < n; i++) {
      free(dp[i]);
    }
    free(dp);
  }
  free(N);
  return 0;
}
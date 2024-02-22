#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int *N;
int n;
vector<vector<int>> dp;
bool solve(int i, int m) {
  if (i == n) return m == 0;
  if (dp[i][m] != -1) return dp[i][m];
  return dp[i][m] = solve(i + 1, m - N[i]) || solve(i + 1, m);
}
int main() {
  int t;
  scanf("%d", &n);
  N = (int *)calloc(n, sizeof(int));
  dp = vector<vector<int>>(n, vector<int>(20001, -1));
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (solve(0, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  free(N);
  return 0;
}
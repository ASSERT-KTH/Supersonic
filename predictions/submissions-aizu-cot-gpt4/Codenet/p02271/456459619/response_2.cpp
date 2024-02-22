#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int *N;
bool dp[2000][2000];
int n;
void solve() {
  dp[0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2000; j++) {
      if (j < N[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = dp[i][j] || dp[i][j - N[i]];
      }
    }
  }
}
int main() {
  int t;
  scanf("%d", &n);
  N = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  solve();
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (dp[n][p]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  free(N);
  return 0;
}
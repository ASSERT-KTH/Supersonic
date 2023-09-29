#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 5002;
const int MAX_VAL = 10000000;
int n;
int t[MAX_N - 1];
int dp[MAX_N / 2 + 1][2];
int solve() {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n - 1; i++) {
    for (int j = n / 2; j > 0; j--) {
      dp[j][0] = min(dp[j][0] + t[i], dp[j - 1][1]);
      dp[j][1] = min(dp[j][1] + t[i], dp[j - 1][0]);
    }
  }
  return dp[n / 2][0];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}
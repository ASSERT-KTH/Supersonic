#include <iostream>
using namespace std;

const int MAX_N = 101;
const int MAX_SUM = 20;

int a[MAX_N];
long long dp[MAX_N][MAX_SUM + 1];

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
  }
  
  dp[1][a[1]] = 1;
  
  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= MAX_SUM; j++) {
      if (j - a[i] >= 0)
        dp[i][j] += dp[i - 1][j - a[i]];
      if (j + a[i] <= MAX_SUM)
        dp[i][j] += dp[i - 1][j + a[i]];
    }
  }
  
  printf("%lld\n", dp[N][a[N]]);
  
  return 0;
}
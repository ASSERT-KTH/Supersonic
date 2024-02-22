#include <iostream>
#include <cstring>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[2][5002][2];
  memset(dp, INF, sizeof dp);    // Use memset to initialize the array
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;
  scanf("%d", &n);
  int(*cur)[2] = dp[0], (*prev)[2] = dp[1];  // Introduce pointers for current and previous states
  for (int i = 2; i <= n; i++) {
    swap(cur, prev);    // Swap the pointers for each iteration
    scanf("%d", &c);
    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        cur[j][0] = INF;
      else
        cur[j][0] = min(prev[j - 1][0], prev[j - 1][1] + c);
      cur[j][1] = min(prev[j][0] + c, prev[j][1]);
    }
  }
  printf("%d\n", min(cur[n / 2][0], cur[n / 2][1]));
  return 0;
}
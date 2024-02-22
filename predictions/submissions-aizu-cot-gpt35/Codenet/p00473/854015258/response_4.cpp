#include <cstdio>

int main() {
  const int INF = 1000000000;
  int n;
  static int dp[2][5000 + 2][2];
  
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;
  
  scanf("%d", &n);
  
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    int c;
    
    scanf("%d", &c);
    
    dp[s][0][0] = INF;
    dp[s][0][1] = INF;
    
    int min_val = INF;
    
    for (int j = 1; j <= n / 2; j++) {
      int prev_0 = dp[t][j - 1][0];
      int prev_1 = dp[t][j - 1][1];
      int curr_0 = dp[t][j][0];
      int curr_1 = dp[t][j][1];
      
      if (j > 1) {
        dp[s][j][0] = prev_0 < prev_1 + c ? prev_0 : prev_1 + c;
      }
      
      dp[s][j][1] = curr_0 + c < curr_1 ? curr_0 + c : curr_1;
      
      int val = dp[s][j][0] < dp[s][j][1] ? dp[s][j][0] : dp[s][j][1];
      
      if (val < min_val) {
        min_val = val;
      }
    }
  }
  
  printf("%d\n", min_val);
}
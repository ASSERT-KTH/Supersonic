#include <stdio.h>
#define INF 1e9
#define N 100000

struct Magic {
  int damage, cost;
};

int main() {
  int n, m, hp[101];
  Magic mg[2][101];
  int dp[2][N + 10] = {};
  char type[10];
  
  while (scanf("%d", &n) != EOF && n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &hp[i]);
      
    scanf("%d", &m);
    for (int i = 0, cost, dam; i < m; i++) {
      scanf("%*s %d %s %d", &cost, type, &dam);
      if (dam)
        mg[type[0] == 'A'][i] = {dam, cost};
    }
    
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INF;
        
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < m; i++)
        for (int j = mg[k][i].damage; j <= (N / mg[k][i].damage + 1) * mg[k][i].damage; j++) {
          int min_j = j < N ? j : N;
          dp[k][min_j] = dp[k][min_j] < dp[k][j - mg[k][i].damage] + mg[k][i].cost ? dp[k][min_j] : dp[k][j - mg[k][i].damage] + mg[k][i].cost;
        }
        
    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--)
        dp[i][j] = dp[i][j] < dp[i][j + 1] ? dp[i][j] : dp[i][j + 1];
        
    long long ans = INF;
    for (int i = 0; i <= N; i++) {
      long long cost = dp[1][i];
      for (int j = 0; j < n; j++) {
        int max_hp = hp[j] > i ? hp[j] - i : 0;
        cost += dp[0][max_hp];
      }
      ans = ans < cost ? ans : cost;
    }
    
    printf("%lld\n", ans);
  }
  
  return 0;
}
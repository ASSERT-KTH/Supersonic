#include <cstdio>

double dfs(int d, double l, double r, double P, double E, double T, double dp[]) {
  double mid = (l + r) / 2;

  if(dp[d] != -1) return dp[d];
  
  if (!d){
    if ((T - E < mid && mid < T + E)) dp[d] = 1;
    else dp[d] = 0;
    
    return dp[d];
  }

  if (r < T - E || T + E < l){
    dp[d] = 0;
    return dp[d];
  }

  if (mid >= T) {
    dp[d] = (1.0 - P) * dfs(d - 1, l, mid, P, E, T, dp) + P * dfs(d - 1, mid, r, P, E, T, dp);
  } else {
    dp[d] = (1.0 - P) * dfs(d - 1, mid, r, P, E, T, dp) + P * dfs(d - 1, l, mid, P, E, T, dp);
  }
  
  return dp[d];
}

int main() {
  int K, R, L;
  double P, E, T;
  scanf("%d %d %d %lf %lf %lf", &K, &L, &R, &P, &E, &T);

  double dp[K+1];
  for(int i=0; i<=K; i++) dp[i] = -1;

  printf("%.9f\n", dfs(K, L, R, P, E, T, dp));
  return 0;
}

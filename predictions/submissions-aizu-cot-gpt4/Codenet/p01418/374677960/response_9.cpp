#include <iostream>
#include <cstdio>
using namespace std;

double dfs(int K, double L, double R, double P, double E, double T, vector<vector<double>>& memo) {
  double mid = (L + R) / 2;
  if (K == 0)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (R < T - E || T + E < L)
    return 0;
  if(memo[K][mid] != -1)
    return memo[K][mid];
  
  if (mid >= T)
    return memo[K][mid] = (1.0 - P) * dfs(K - 1, L, mid, P, E, T, memo) + P * dfs(K - 1, mid, R, P, E, T, memo);
  return memo[K][mid] = (1.0 - P) * dfs(K - 1, mid, R, P, E, T, memo) + P * dfs(K - 1, L, mid, P, E, T, memo);
}

int main() {
  int K;
  double L, R, P, E, T;
  cin >> K >> L >> R >> P >> E >> T;
  vector<vector<double>> memo(K+1, vector<double>(10000, -1));
  printf("%.9f\n", dfs(K, L, R, P, E, T, memo));
  return 0;
}
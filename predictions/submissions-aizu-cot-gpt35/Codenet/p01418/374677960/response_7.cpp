#include <iostream>
#include <cstdio>
using namespace std;

double P, E, T;
double memo[101][1001];

double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;

  if (memo[d][r] != -1) {
    return memo[d][r];
  }

  double result;
  if (mid >= T)
    result = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else
    result = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);

  memo[d][r] = result;
  return result;
}

int main() {
  int K, L;
  cin >> K >> L >> P >> E >> T;
  
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= L; j++) {
      memo[i][j] = -1;
    }
  }
  
  printf("%.9f\n", dfs(K, 0, L));
  return 0;
}
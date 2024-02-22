#include <iostream>
#include <cstdio>
using namespace std;

int K, R, L;
double P, E, T;

double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;

  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;

  if (r < T - E || T + E < l)
    return 0;

  double left_dfs = dfs(d - 1, l, mid);
  double right_dfs = dfs(d - 1, mid, r);

  if (mid >= T)
    return (1.0 - P) * left_dfs + P * right_dfs;

  return (1.0 - P) * right_dfs + P * left_dfs;
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));

  return 0;
}
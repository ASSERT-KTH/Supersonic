#include <iostream>
#include <cstdio>

using namespace std;

int K;
double L, R, P, E, T;

double dfs(int d, double l, double r) {
  if (r < T - E || T + E < l) return 0;
  if (!d) return (T - E < r && l < T + E) ? 1 : 0;
  double mid = l + (r - l) / 2;
  if (mid >= T) return (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else return (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}
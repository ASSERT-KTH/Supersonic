#include <bits/stdc++.h>
using namespace std;

int K, R, L;
double P, E, T;

double dfs(int d, double l, double r, double mid) {
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T)
    return (1.0 - P) * dfs(d - 1, l, mid, (l + mid) / 2) + P * dfs(d - 1, mid, r, (mid + r) / 2);
  return (1.0 - P) * dfs(d - 1, mid, r, (mid + r) / 2) + P * dfs(d - 1, l, mid, (l + mid) / 2);
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R, (L + R) / 2));
  return 0;
}
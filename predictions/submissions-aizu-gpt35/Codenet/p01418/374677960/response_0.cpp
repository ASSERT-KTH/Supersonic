#include <bits/stdc++.h>
using namespace std;
int K, R, L;
double P, E, T;
double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T){
    double p = dfs(d - 1, l, mid);
    return (1.0 - P) * p + P * dfs(d - 1, mid, r);
  }
  double p = dfs(d - 1, mid, r);
  return (1.0 - P) * p + P * dfs(d - 1, l, mid);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}
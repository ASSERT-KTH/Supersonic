#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int K;
double L, R, P, E, T;
double dfs(int d, double l, double r) {
  if (r < T - E || T + E < l)
    return 0;
  if (d == 0)
    return (fabs(T - l) <= E && fabs(T - r) <= E) ? 1 : 0;
  double mid = (l + r) / 2;
  if (mid >= T)
    return P * dfs(d - 1, mid, r) + (1.0 - P) * dfs(d - 1, l, mid);
  return (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}
int main() {
  cin >> K >> L >> R >> P >> E >> T;
  cout << fixed << setprecision(9) << dfs(K, L, R) << endl;
  return 0;
}
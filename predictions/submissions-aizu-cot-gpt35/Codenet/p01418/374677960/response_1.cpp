#include <iostream>
using namespace std;

int K, R, L;
double P, E, T;

double dfs(int d, double l, double r) {
  double mid = (l + r) * 0.5;
  if (d == 0)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E)
    return 0;
  if (mid >= T + E)
    return (1 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  return (1 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  puts(to_string(dfs(K, L, R)).c_str());
  return 0;
}
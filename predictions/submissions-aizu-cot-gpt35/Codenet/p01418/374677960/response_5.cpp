#include <iostream>
using namespace std;

int K, R, L;
double P, E, T;

int dfs(int d, int l, int r) {
  int mid = l + (r - l) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T)
    return (1 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  return (1 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  cout << dfs(K, L, R) << endl;
  return 0;
}
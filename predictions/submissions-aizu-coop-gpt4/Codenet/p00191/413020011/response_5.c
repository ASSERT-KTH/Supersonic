#include <iostream>
#include <unordered_map>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
double a[101][101];
unordered_map<int, double> memo;

double solve(int n, int m, int k, int p) {
  if (m == 1)
    return 1;
  int key = p * 10000 + m * 100 + k;
  if (memo.find(key) != memo.end())
    return memo[key];
  double res = 0;
  rep(i, n) res = max(res, solve(n, m - 1, p, i) * a[p][i]);
  return memo[key] = res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  double res;
  while (cin >> n >> m, n | m) {
    memo.clear();
    rep(i, n) rep(j, n) cin >> a[i][j];
    res = 0;
    rep(i, n) rep(j, n) res = max(res, solve(n, m, i, j));
    cout << fixed << setprecision(2) << res << "\n";
  }
  return 0;
}
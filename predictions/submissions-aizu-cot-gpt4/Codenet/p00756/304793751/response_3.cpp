#include <bits/stdc++.h>
using namespace std;

bool ok(int a, int bit, vector<int>& x, vector<int>& y, vector<int>& r) {
  for (int i = 0; i < a; i++) {
    int shifted_bit = (bit >> i) & 1;
    if (shifted_bit == 0)
      continue;
    int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return false;
  }
  return true;
}

int dfs(int bit, int n, vector<int>& c, vector<bool>& memo, vector<int>& x, vector<int>& y, vector<int>& r) {
  memo[bit] = true;
  int ret = n;
  for (int i = 0; i < n; i++) {
    int shifted_bit = (bit >> i) & 1;
    if (shifted_bit)
      ret--;
  }
  for (int i = 0; i < n; i++) {
    int shifted_bit = (bit >> i) & 1;
    if (shifted_bit == 0 || !ok(i, bit, x, y, r))
      continue;
    for (int j = i + 1; j < n; j++) {
      int shifted_bit_j = (bit >> j) & 1;
      if (shifted_bit_j == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit, x, y, r) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit, n, c, memo, x, y, r));
      }
    }
  }
  return ret;
}

void solve(int n, vector<int>& c, vector<bool>& memo, vector<int>& x, vector<int>& y, vector<int>& r) {
  fill_n(memo.begin(), 1 << n, false);
  cout << dfs((1 << n) - 1, n, c, memo, x, y, r) << endl;
}

bool input(int& n, vector<int>& x, vector<int>& y, vector<int>& r, vector<int>& c) {
  cin >> n;
  if (!n)
    return false;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> r[i] >> c[i];
  return true;
}

int main() {
  int n;
  vector<int> x(24), y(24), r(24), c(24);
  vector<bool> memo(1 << 24);
  while (input(n, x, y, r, c))
    solve(n, c, memo, x, y, r);
  return 0;
}
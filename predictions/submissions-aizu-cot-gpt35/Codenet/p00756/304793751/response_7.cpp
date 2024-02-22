#include <bits/stdc++.h>
using namespace std;

int n;
int x[24], y[24], r[24], c[24];
int memo[1 << 24];

bool ok(int a, int b) {
  int dist = (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
  int sum = (r[a] + r[b]) * (r[a] + r[b]);
  return dist >= sum;
}

int dfs(int bit) {
  if (memo[bit] != -1)
    return memo[bit];

  int ret = __builtin_popcount(bit);
  for (int i = 0; i < n; i++) {
    if ((bit >> i) & 1) {
      for (int j = i + 1; j < n; j++) {
        if ((bit >> j) & 1 && c[i] == c[j] && ok(i, j)) {
          int to_bit = bit ^ (1 << i) ^ (1 << j);
          ret = max(ret, dfs(to_bit));
        }
      }
    }
  }

  return memo[bit] = ret;
}

void solve() {
  memset(memo, -1, sizeof(memo));
  cout << dfs((1 << n) - 1) << endl;
}

bool input() {
  cin >> n;
  if (!n)
    return false;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> r[i] >> c[i];
  return true;
}

int main() {
  while (input())
    solve();
  return 0;
}
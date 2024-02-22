#include <bits/stdc++.h>
using namespace std;

int n;
int x[24], y[24], r[24], c[24];
vector<bool> memo;
vector<int> dp;

bool ok(int a, int bit) {
  int dist = (x[a] - x[bit]) * (x[a] - x[bit]) + (y[a] - y[bit]) * (y[a] - y[bit]);
  int sum = (r[a] + r[bit]) * (r[a] + r[bit]);
  return (dist <= sum);
}

int dfs(int bit) {
  if (dp[bit] != -1) {
    return dp[bit];
  }

  dp[bit] = n;

  for (int i = 0; i < n; i++) {
    if ((bit >> i) & 1) {
      dp[bit]--;
    }
  }

  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || !ok(i, bit)) {
      continue;
    }

    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j]) {
        continue;
      }

      int to_bit = (bit ^ (1 << i)) ^ (1 << j);

      if (ok(j, bit) && dp[to_bit] == -1) {
        dp[bit] = max(dp[bit], dfs(to_bit));
      }
    }
  }

  return dp[bit];
}

void solve() {
  fill(dp.begin(), dp.end(), -1);
  cout << dfs((1 << n) - 1) << endl;
}

bool input() {
  cin >> n;
  if (!n) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i] >> c[i];
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (input()) {
    solve();
  }

  return 0;
}
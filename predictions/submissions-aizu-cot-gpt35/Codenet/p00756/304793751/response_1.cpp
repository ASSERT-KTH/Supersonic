#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int n;
int x[24], y[24], r[24], c[24];
int memo[1 << 24];
int dist[24][24];

bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    if (dist[i][a] < (r[i] + r[a]) * (r[i] + r[a]))
      return false;
  }
  return true;
}

int dfs(int bit) {
  memset(memo, -1, sizeof(memo));
  stack<int> stk;
  stk.push(bit);
  memo[bit] = n;

  int ret = n;
  while (!stk.empty()) {
    int cur = stk.top();
    stk.pop();
    ret = max(ret, memo[cur]);

    for (int i = 0; i < n; i++) {
      if (((cur >> i) & 1) == 0 || !ok(i, cur))
        continue;
      for (int j = i + 1; j < n; j++) {
        if (((cur >> j) & 1) == 0 || c[i] != c[j])
          continue;
        int to_bit = (cur ^ (1 << i)) ^ (1 << j);
        if (ok(j, cur) && memo[to_bit] == -1) {
          stk.push(to_bit);
          memo[to_bit] = memo[cur] - 2;
        }
      }
    }
  }
  return ret;
}

void solve() {
  cin >> n;
  while (n) {
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i] >> r[i] >> c[i];

    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        dist[i][j] = dist[j][i] = dx * dx + dy * dy;
      }
    }

    cout << dfs((1 << n) - 1) << endl;

    cin >> n;
  }
}

int main() {
  solve();
  return 0;
}
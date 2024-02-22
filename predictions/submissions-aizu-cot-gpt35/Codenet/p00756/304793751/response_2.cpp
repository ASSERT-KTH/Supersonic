#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int n;
int x[24], y[24], r[24], c[24];
bitset<1 << 24> memo;
int dist[24][24];

bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist[i][a] < sum)
      return false;
  }
  return true;
}

int dfs(int bit) {
  memo[bit] = true;
  int ret = n;
  for (int i = 0; i < n; i++)
    if ((bit >> i) & 1)
      ret--;

  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || ok(i, bit) == false)
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        break;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return ret;
}

void solve() {
  memo.reset();
  cout << dfs((1 << n) - 1) << endl;
}

bool input() {
  cin >> n;
  if (!n)
    return false;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> r[i] >> c[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      dist[i][j] = dist[j][i] = dx * dx + dy * dy;
    }
  }

  return true;
}

int main() {
  while (input())
    solve();
  return 0;
}
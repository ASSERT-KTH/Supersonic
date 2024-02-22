#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 24;
int n;
int x[MAX_N], y[MAX_N], r[MAX_N], c[MAX_N];
bool memo[1 << MAX_N];

bool ok(int a, int bit, int dist) {
  int sum = (r[a] + r[a]) * (r[a] + r[a]);
  return dist >= sum;
}

int dfs(int bit) {
  memo[bit] = true;
  int ret = n;
  for (int i = 0; i < n; i++) {
    if ((bit >> i) & 1)
      ret--;
  }
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || ok(i, bit, 0) == false)
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit, dist) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return ret;
}

void solve() {
  memset(memo, false, sizeof(memo));
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
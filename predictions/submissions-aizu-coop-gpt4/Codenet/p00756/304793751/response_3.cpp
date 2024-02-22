#include <bits/stdc++.h>
using namespace std;
int n;
int x[24], y[24], r[24], c[24];
bool memo[1 << 24], okMemo[24][1 << 24];

bool ok(int a, int bit) {
  if(okMemo[a][bit] != -1) return okMemo[a][bit];
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return okMemo[a][bit] = false;
  }
  return okMemo[a][bit] = true;
}

int dfs(int bit) {
  if(memo[bit]) return bit;
  memo[bit] = true;
  int ret = n;
  for (int i = 0; i < n; i++)
    if ((bit >> i) & 1)
      ret--;
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || !ok(i, bit))
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return ret;
}

void solve() {
  memset(memo, 0, sizeof(memo));
  memset(okMemo, -1, sizeof(okMemo));
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
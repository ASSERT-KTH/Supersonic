#include <bits/stdc++.h>
using namespace std;

const int MAXN = 24;
int n;
int x[MAXN], y[MAXN], r[MAXN], c[MAXN];
bool memo[1 << MAXN];
bool ok(int a, int bit) {
  const int xa = x[a], ya = y[a], ra = r[a];
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0) continue;
    int dist = (x[i] - xa) * (x[i] - xa) + (y[i] - ya) * (y[i] - ya);
    if (dist < (r[i] + ra) * (r[i] + ra)) return false;
  }
  return true;
}

int dfs(int bit, int cnt) {
  memo[bit] = true;
  int ret = n - cnt;
  for (int i = 0; i < n; i++) {
    if ((bit >> i) & 1) continue;
    for (int j = i + 1; j < n; j++) {
      if ((bit >> j) & 1 || c[i] != c[j]) continue;
      int to_bit = bit | (1 << i) | (1 << j);
      if (ok(i, to_bit) && ok(j, to_bit) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit, cnt + 2));
      }
    }
  }
  return ret;
}

void solve() {
  fill_n(memo, 1 << n, false);
  cout << dfs(0, 0) << endl;
}

bool input() {
  cin >> n;
  if (!n) return false;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i] >> c[i];
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (input()) solve();
  return 0;
}
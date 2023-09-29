#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1005;
int n, m, l, k, a, h, t1, t2, t3;
int b[MAXN][MAXN], x[MAXN][MAXN];
set<int> rei;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    rei.clear();
    rei.insert(a), rei.insert(h);
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < n; ++j)
        x[i][j] = b[i][j] = (i == j ? 0 : INT_MAX);
    for (int i = 0; i < l; ++i) {
      int re;
      cin >> re;
      rei.insert(re);
    }
    for (int i = 0; i < k; ++i) {
      cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
    }
    for (int o = 0; o < n; ++o)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
    for (int i : rei)
      for (int j : rei)
        if (b[i][j] <= m)
          x[i][j] = b[i][j];
    for (int o = 0; o < n; ++o)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
    if (x[a][h] >= INT_MAX)
      cout << "Help!\n";
    else if (x[a][h] < m)
      cout << x[a][h] << '\n';
    else
      cout << x[a][h] * 2 - m << '\n';
  }
  return 0;
}
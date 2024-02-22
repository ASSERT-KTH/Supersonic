#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    unordered_set<int> rei;
    rei.insert(a), rei.insert(h);
    vector<vector<int>> b(n, vector<int>(n, INF));
    int re;
    r(i, l) cin >> re, rei.insert(re);
    r(i, k) cin >> t1 >> t2 >> t3, b[t1][t2] = b[t2][t1] = t3;
    r(o, n) r(i, n) r(j, n) if (rei.count(i) && rei.count(j)) b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
    if (b[a][h] >= INF)
      cout << "Help!" << endl;
    else if (b[a][h] < m)
      cout << b[a][h] << endl;
    else
      cout << b[a][h] * 2 - m << endl;
  }
}
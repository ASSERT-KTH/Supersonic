#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    set<int> rei;
    rei.insert(a), rei.insert(h);
    vector<vector<int>> b(n, vector<int>(n, INF)), x(n, vector<int>(n, INF));
    r(i, l) cin >> re, rei.insert(re);
    r(i, k) cin >> t1 >> t2 >> t3, b[t1][t2] = b[t2][t1] = t3;
    r(o, n) for(auto i: rei) for(auto j: rei) b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
    for(auto i: rei) for(auto j: rei) if (b[i][j] <= m) x[i][j] = b[i][j];
    r(o, n) for(auto i: rei) for(auto j: rei) x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
    if (x[a][h] >= INF)
      cout << "Help!" << endl;
    else if (x[a][h] < m)
      cout << x[a][h] << endl;
    else
      cout << x[a][h] * 2 - m << endl;
  }
}
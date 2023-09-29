#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    set<int> rei;
    rei.insert(a), rei.insert(h);
    int b[n][n], re, x[n][n];
    r(i, n) r(j, n) x[i][j] = b[i][j] = INF;
    r(i, l) cin >> re, rei.insert(re);
    r(i, k) cin >> t1 >> t2 >> t3, b[t1][t2] = b[t2][t1] = t3;
    r(o, n) r(i, n) r(j, n) b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
    r(i, n) if (rei.count(i)) r(j, n) if (rei.count(j)) if (b[i][j] <= m)
        x[i][j] = b[i][j];
    r(o, n) r(i, n) r(j, n) x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
    if (x[a][h] >= INF)
      cout << "Help!" << endl;
    else if (x[a][h] < m)
      cout << x[a][h] << endl;
    else
 
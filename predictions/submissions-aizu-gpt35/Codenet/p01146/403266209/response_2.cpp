#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;
const int MAXN = 205;
int n, m, l, k, a, h, t1, t2, t3;
int b[MAXN][MAXN], x[MAXN][MAXN];
set<int> rei;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    rei.clear();
    rei.insert(a), rei.insert(h);
    r(i, n) r(j, n) x[i][j] = b[i][j] = INF;
    r(i, l) {
      int re; cin >> re; rei.insert(re);
    }
    r(i, k) {
      cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
    }
    r(o, n) r(i, n) r(j, n) b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
    r(i, n) if (rei.count(i)) r(j, n) if (rei.count(j)) if (b[i][j] <= m)
        x[i][j] = b[i][j];
    r(o, n) r(i, n) r(j, n) x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
    if (x[a][h] >= INF)
      cout << "Help!" << endl;
    else if (x[a][h] < m)
      cout << x[a][h] << endl;
    else
      cout << x[a][h] * 2 - m << endl;
  }
}
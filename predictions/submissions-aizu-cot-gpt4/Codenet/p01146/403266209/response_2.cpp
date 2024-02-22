#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;
int main() {
  int n, m, l, k, a, h;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    unordered_set<int> rei;
    rei.insert(a), rei.insert(h);
    vector<vector<int>> b(n, vector<int>(n, INF));
    vector<vector<int>> x(n, vector<int>(n, INF));
    int re;
    r(i, l) {
        cin >> re;
        rei.insert(re);
    }
    r(i, k) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        b[t1][t2] = b[t2][t1] = t3;
    }
    r(o, n) r(i, n) r(j, n) {
        b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
        if (rei.count(i) && rei.count(j)) {
            x[i][j] = b[i][j];
        }
    }
    r(o, n) r(i, n) r(j, n) x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
    if (x[a][h] >= INF)
      cout << "Help!" << endl;
    else if (x[a][h] < m)
      cout << x[a][h] << endl;
    else
      cout << x[a][h] * 2 - m << endl;
  }
}
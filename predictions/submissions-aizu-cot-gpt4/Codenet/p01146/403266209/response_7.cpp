#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

void FloydWarshall(int n, vector<vector<int>>& mat) {
    r(o, n) r(i, n) r(j, n) mat[i][j] = min(mat[i][j], mat[i][o] + mat[o][j]);
}

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    vector<bool> rei(n, false);
    rei[a] = true, rei[h] = true;
    vector<vector<int>> b(n, vector<int>(n, INF)), x(n, vector<int>(n, INF));
    r(i, l) cin >> t1, rei[t1] = true;
    r(i, k) cin >> t1 >> t2 >> t3, b[t1][t2] = b[t2][t1] = t3;
    FloydWarshall(n, b);
    r(i, n) if (rei[i]) r(j, n) if (rei[j]) if (b[i][j] <= m)
        x[i][j] = b[i][j];
    FloydWarshall(n, x);
    if (x[a][h] >= INF)
      cout << "Help!" << endl;
    else if (x[a][h] < m)
      cout << x[a][h] << endl;
    else
      cout << x[a][h] * 2 - m << endl;
  }
}
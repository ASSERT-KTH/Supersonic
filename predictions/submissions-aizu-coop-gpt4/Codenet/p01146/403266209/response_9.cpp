#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    vector<int> rei;
    rei.push_back(a), rei.push_back(h);
    vector<bool> is_rei(n, false);
    is_rei[a] = is_rei[h] = true;
    vector<vector<int>> b(n, vector<int>(n, INF));
    for (int i = 0; i < l; i++) {
      cin >> t1;
      rei.push_back(t1);
      is_rei[t1] = true;
    }
    for (int i = 0; i < k; i++) {
      cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
    }
    for (int o = 0; o < n; o++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
    for (int i = 0; i < n; i++)
      if (!is_rei[i])
        for (int j = 0; j < n; j++)
          b[i][j] = b[j][i] = INF;
    if (b[a][h] >= INF)
      cout << "Help!" << endl;
    else if (b[a][h] < m)
      cout << b[a][h] << endl;
    else
      cout << b[a][h] * 2 - m << endl;
  }
}
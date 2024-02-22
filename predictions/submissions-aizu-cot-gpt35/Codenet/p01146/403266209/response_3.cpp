#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define INF 1e9

using namespace std;

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    set<int> rei;
    rei.insert(a);
    rei.insert(h);
    int re;
    for (int i = 0; i < l; i++) {
      cin >> re;
      rei.insert(re);
    }
    vector<vector<int>> b(n, vector<int>(n, INF));
    for (int i = 0; i < k; i++) {
      cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
    }
    for (int o = 0; o < n; o++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
        }
      }
    }
    vector<vector<int>> x(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
      if (rei.count(i)) {
        for (int j = 0; j < n; j++) {
          if (rei.count(j) && b[i][j] <= m) {
            x[i][j] = b[i][j];
          }
        }
      }
    }
    for (int o = 0; o < n; o++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
        }
      }
    }
    int result = x[a][h];
    if (result >= INF)
      cout << "Help!" << endl;
    else if (result < m)
      cout << result << endl;
    else
      cout << result * 2 - m << endl;
  }
}
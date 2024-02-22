#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define INF 1e9

using namespace std;

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    vector<int> rei;
    rei.push_back(a);
    rei.push_back(h);
    for (int i = 0; i < l; i++) {
      int re;
      cin >> re;
      rei.push_back(re);
    }
    sort(rei.begin(), rei.end());

    vector<vector<int>> b(n, vector<int>(n, INF));
    vector<vector<int>> x(n, vector<int>(n, INF));

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

    for (int i = 0; i < n; i++) {
      if (binary_search(rei.begin(), rei.end(), i)) {
        for (int j = 0; j < n; j++) {
          if (binary_search(rei.begin(), rei.end(), j) && b[i][j] <= m) {
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

    int minDist = x[a][h];

    if (minDist >= INF) {
      cout << "Help!" << endl;
    } else if (minDist < m) {
      cout << minDist << endl;
    } else {
      cout << minDist * 2 - m << endl;
    }
  }
}
#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    vector<int> rei;
    rei.push_back(a), rei.push_back(h);
    vector<vector<int>> x(n, vector<int>(n, INF));
    r(i, l) {
      cin >> t1;
      rei.push_back(t1);
    }
    r(i, k) {
      cin >> t1 >> t2 >> t3;
      x[t1][t2] = x[t2][t1] = t3;
    }
    r(o, n) {
      r(i, n) {
        r(j, n) {
          x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
        }
      }
    }
    r(o, n) {
      r(i, n) {
        r(j, n) {
          x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
        }
      }
    }
    if (x[a][h] >= INF)
      cout << "Help!" << endl;
    else
      cout << x[a][h] * 2 - m << endl;
  }
}
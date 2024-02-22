#include <iostream>
#include <unordered_set>
#include <cstring>
#define INF 1e9
using namespace std;

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    unordered_set<int> rei;
    rei.insert(a);
    rei.insert(h);
    int b[n][n], x[n][n];
    memset(b, INF, sizeof(b));
    memset(x, INF, sizeof(x));

    for (int i = 0; i < l; i++) {
      int re;
      cin >> re;
      rei.insert(re);
    }

    for (int i = 0; i < k; i++) {
      cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
    }

    for (int o = 0; o < n; o++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (b[i][o] + b[o][j] < b[i][j]) {
            b[i][j] = b[i][o] + b[o][j];
          }
        }
      }
    }

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
          if (x[i][o] + x[o][j] < x[i][j]) {
            x[i][j] = x[i][o] + x[o][j];
          }
        }
      }
    }

    int result;
    if (x[a][h] >= INF) {
      result = -1;
    } else if (x[a][h] < m) {
      result = x[a][h];
    } else {
      result = x[a][h] * 2 - m;
    }

    cout << result << endl;
  }
}
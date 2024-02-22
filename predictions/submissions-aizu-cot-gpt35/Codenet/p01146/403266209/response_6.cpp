#include <iostream>
#include <vector>
#include <cstring>
#define INF 1e9
using namespace std;

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (scanf("%d %d %d %d %d %d", &n, &m, &l, &k, &a, &h), n) {
    vector<int> rei;
    rei.push_back(a);
    rei.push_back(h);
    vector<vector<int>> b(n, vector<int>(n, INF));
    vector<vector<int>> x(n, vector<int>(n, INF));
    for (int i = 0; i < l; i++) {
      int re;
      scanf("%d", &re);
      rei.push_back(re);
    }
    for (int i = 0; i < k; i++) {
      scanf("%d %d %d", &t1, &t2, &t3);
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
      if (find(rei.begin(), rei.end(), i) != rei.end()) {
        for (int j = 0; j < n; j++) {
          if (find(rei.begin(), rei.end(), j) != rei.end() && b[i][j] <= m) {
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
    if (x[a][h] >= INF)
      printf("Help!\n");
    else if (x[a][h] < m)
      printf("%d\n", x[a][h]);
    else
      printf("%d\n", x[a][h] * 2 - m);
  }
  return 0;
}
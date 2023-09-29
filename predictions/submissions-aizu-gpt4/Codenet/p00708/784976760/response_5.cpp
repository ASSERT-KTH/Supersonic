#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M], a[M], b[M];
pair<double, int> node[M];

inline int root(int a) { return parent[a] == a ? a : (parent[a] = root(parent[a])); }

inline int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x != y) {
    parent[x] = y;
    return 1;
  }
  return 0;
}

int main() {
  int i, j, m, n;
  double x, y, z, r;
  while(scanf("%d", &n), n) {
    vector<vector<double>> v(n, vector<double>(4));
    for (i = 0; i < n; ++i) {
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
      parent[i] = i;
    }
    for (m = i = 0; i < n; ++i)
      for (j = i + 1; j < n; ++j) {
        x = 0;
        for (int k = 0; k < 3; ++k)
          x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        x = sqrt(x) - v[i][3] - v[j][3];
        if (x <= 0) {
          unite(i, j);
        } else {
          a[m] = i, b[m] = j, node[m] = {x, m};
          ++m;
        }
      }
    sort(node, node + m);
    x = 0;
    for (i = 0; i < m; ++i)
      if (unite(a[node[i].second], b[node[i].second]))
        x += node[i].first;
    printf("%.3f\n", x);
  }
}
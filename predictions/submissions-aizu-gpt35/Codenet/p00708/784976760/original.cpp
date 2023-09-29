#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M], a[M], b[M];
pair<double, int> node[M];
int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }
int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}
int main() {
  int i, j, k, m, n;
  double x, y, z, r;
  for (; scanf("%d", &n), n;) {
    vector<vector<double>> v;
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &x, &y, &z, &r), v.push_back({x, y, z, r});
    for (i = 0; i < n; i++)
      parent[i] = i;
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        for (x = k = 0; k < 3; k++)
          x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        x = sqrt(x) - v[i][3] - v[j][3];
        if (x <= 0)
          unite(i, j);
        else
          a[m] = i, b[m] = j, node[m].first = x, node[m++].second = m;
      }
    sort(node, node + m);
    for (x = i = 0; i < m; i++)
      if (unite(a[node[i].second], b[node[i].second]))
        x += node[i].first;
    printf("%.3f\n", x);
  }
}

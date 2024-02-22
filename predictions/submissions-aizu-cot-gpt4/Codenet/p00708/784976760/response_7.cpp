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
        if (v[i][3] + v[j][3] >= sqrt(pow(v[i][0] - v[j][0], 2) + pow(v[i][1] - v[j][1], 2) + pow(v[i][2] - v[j][2], 2))) {
          unite(i, j);
        } else {
          x = sqrt(pow(v[i][0] - v[j][0], 2) + pow(v[i][1] - v[j][1], 2) + pow(v[i][2] - v[j][2], 2)) - v[i][3] - v[j][3];
          a[m] = i, b[m] = j, node[m].first = x, node[m++].second = m;
        }
      }
    sort(node, node + m);
    for (x = i = 0; i < m; i++)
      if (unite(a[node[i].second], b[node[i].second]))
        x += node[i].first;
    printf("%.3f\n", x);
  }
}
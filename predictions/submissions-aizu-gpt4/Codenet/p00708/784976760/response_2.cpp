#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M], a[M], b[M];
pair<double, int> node[M];
int root(int a) { 
    while(a != parent[a]) {
        parent[a] = parent[parent[a]];
        a = parent[a];
    }
    return a;
}
void unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x != y)
    parent[x] = y;
}
int main() {
  int i, j, m, n;
  double x, y, z, r;
  while(scanf("%d", &n) == 1 && n) {
    vector<vector<double>> v(n, vector<double>(4));
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
    iota(parent, parent + n, 0);
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        double dist = 0;
        for (int k = 0; k < 3; ++k)
          dist += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        dist = sqrt(dist) - v[i][3] - v[j][3];
        if (dist <= 0)
          unite(i, j);
        else {
          a[m] = i, b[m] = j;
          node[m] = make_pair(dist, m);
          ++m;
        }
      }
    sort(node, node + m);
    double total = 0;
    for (i = 0; i < m; i++)
      if (root(a[node[i].second]) != root(b[node[i].second])) {
        unite(a[node[i].second], b[node[i].second]);
        total += node[i].first;
      }
    printf("%.3f\n", total);
  }
}
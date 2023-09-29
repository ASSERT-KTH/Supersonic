#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M], a[M], b[M];
double dist[M];
vector<vector<double>> v;
int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }
int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}
double compute_distance(int i, int j) {
  double x = 0;
  for (int k = 0; k < 3; k++)
    x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
  return sqrt(x) - v[i][3] - v[j][3];
}
int main() {
  int i, j, k, m, n;
  double x, y, z, r;
  for (; scanf("%d", &n), n;) {
    v.resize(n);
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &x, &y, &z, &r), v[i] = {x, y, z, r};
    for (i = 0; i < n; i++)
      parent[i] = i;
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        x = compute_distance(i, j);
        if (x <= 0)
          unite(i, j);
        else
          a[m] = i, b[m] = j, dist[m++] = x;
      }
    double ans = 0;
    sort(dist, dist + m);
    for (i = 0; i < m; i++)
      if (unite(a[i], b[i]))
        ans += dist[i];
    printf("%.3f\n", ans);
  }
}
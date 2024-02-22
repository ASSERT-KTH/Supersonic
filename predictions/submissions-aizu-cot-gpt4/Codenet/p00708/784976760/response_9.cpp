#include <algorithm>
#include <cstdio>
#define M 9999
int parent[M], a[M], b[M];
double x[M], y[M], z[M], r[M];
std::pair<double, int> node[M];
int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }
bool unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return false;
  parent[x] = y;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, k, m, n;
  double d;
  while (scanf("%d", &n), n) {
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &x[i], &y[i], &z[i], &r[i]);
    for (i = 0; i < n; i++)
      parent[i] = i;
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        d = 0;
        for (k = 0; k < 3; k++)
          d += ((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j])) + ((z[i] - z[j]) * (z[i] - z[j]));
        d = d - (r[i] + r[j]) * (r[i] + r[j]);
        if (d <= 0)
          unite(i, j);
        else
          a[m] = i, b[m] = j, node[m].first = d, node[m++].second = m;
      }
    sort(node, node + m);
    for (d = i = 0; i < m; i++)
      if (unite(a[node[i].second], b[node[i].second]))
        d += node[i].first;
    printf("%.3f\n", sqrt(d));
  }
}
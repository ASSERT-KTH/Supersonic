#include <algorithm>
#include <cmath>
#include <cstdio>
#define M 9999
int parent[M], a[M], b[M];
double node[M];
double v[M][4];
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
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
    for (i = 0; i < n; i++)
      parent[i] = i;
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        for (x = k = 0; k < 3; k++)
          x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        x -= v[i][3] * v[i][3] + v[j][3] * v[j][3];
        if (x <= 0)
          unite(i, j);
        else
          a[m] = i, b[m] = j, node[m++] = sqrt(x);
      }
    std::sort(node, node + m);
    for (x = i = 0; i < m; i++)
      if (unite(a[i], b[i]))
        x += node[i];
    printf("%.3f\n", x);
  }
}
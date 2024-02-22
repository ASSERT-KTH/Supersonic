#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define M 9999
int parent[M], a[M][M], b[M][M];
double node[M][M], r[M];
int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }
int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}
int main() {
  int i, j, k, n;
  double x, y, z;
  for (; scanf("%d", &n), n;) {
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &x, &y, &z, &r[i]);
    for (i = 0; i < n; i++)
      parent[i] = i;
    for (i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        a[i][j] = i, b[i][j] = j;
        node[i][j] = sqrt((x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z)) - r[i] - r[j];
        if (node[i][j] <= 0)
          unite(i, j);
      }
    sort(node[0], node[0] + n * n);
    for (x = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++)
        if (unite(a[i][j], b[i][j]))
          x += node[i][j];
    printf("%.3f\n", x);
  }
}
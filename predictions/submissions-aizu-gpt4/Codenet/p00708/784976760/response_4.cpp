#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M];
pair<int, int> edges[M];
pair<double, int> node[M];
double r[M], x[M], y[M], z[M];

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
  double dist;

  while(scanf("%d", &n), n) {
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &x[i], &y[i], &z[i], &r[i]);
    for (i = 0; i < n; i++)
      parent[i] = i;
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2)) - r[i] - r[j];
        if (dist <= 0)
          unite(i, j);
        else
          edges[m] = {i, j}, node[m].first = dist, node[m++].second = m;
      }
    sort(node, node + m);
    for (dist = i = 0; i < m; i++)
      if (unite(edges[node[i].second].first, edges[node[i].second].second))
        dist += node[i].first;
    printf("%.3f\n", dist);
  }
}
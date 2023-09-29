#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M], a[M], b[M];
double dist[M];
vector<double> v[M];
pair<double, int> node[M];
int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }
int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}
double distance(int i, int j) {
  double x = 0, diff;
  for (int k = 0; k < 3; k++) {
    diff = v[i][k] - v[j][k];
    x += diff * diff;
  }
  return sqrt(x) - v[i][3] - v[j][3];
}
int main() {
  int i, j, m, n;
  double x;
  while (scanf("%d", &n), n) {
    for (i = 0; i < n; i++) {
      v[i].resize(4);
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
      parent[i] = i;
    }
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        x = distance(i, j);
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
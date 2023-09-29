#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M], rank[M], a[M], b[M];
pair<double, int> node[M];
int root(int a) { 
  if (parent[a] == a) return a;
  return parent[a] = root(parent[a]); 
}
void unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y) return;
  if (rank[x] < rank[y]) swap(x, y);
  if (rank[x] == rank[y]) rank[x]++;
  parent[y] = x;
}
int main() {
  int i, j, k, m, n;
  double x, y, z, r;
  for (; scanf("%d", &n), n;) {
    vector<vector<double>> v(n, vector<double>(4));
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
    for (i = 0; i < n; i++)
      parent[i] = i, rank[i] = 0;
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        for (x = k = 0; k < 3; k++)
          x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        x = sqrt(x) - v[i][3] - v[j][3];
        if (x <= 0) unite(i, j);
        else a[m] = i, b[m] = j, node[m].first = x, node[m].second = m, m++;
      }
    sort(node, node + m);
    for (x = i = 0; i < m; i++)
      if (root(a[node[i].second]) != root(b[node[i].second]))
        unite(a[node[i].second], b[node[i].second]), x += node[i].first;
    printf("%.3f\n", x);
  }
}
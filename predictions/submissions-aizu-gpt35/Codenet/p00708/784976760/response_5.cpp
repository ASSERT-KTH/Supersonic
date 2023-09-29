#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define M 10000
int parent[M], a[M], b[M], rank[M];
double x[M], y[M], z[M], r[M], dist[M];
bool vis[M];
int n, m;
void init() {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}
int root(int a) {
  if (parent[a] == a) {
    return a;
  }
  return parent[a] = root(parent[a]);
}
int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y) {
    return 0;
  }
  if (rank[x] < rank[y]) {
    parent[x] = y;
  } else {
    parent[y] = x;
    if (rank[x] == rank[y]) {
      rank[x]++;
    }
  }
  return 1;
}
int main() {
  while (scanf("%d", &n), n) {
    memset(vis, false, sizeof(vis));
    m = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &x[i], &y[i], &z[i], &r[i]);
      for (int j = 0; j < i; j++) {
        double tmp = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j])) - r[i] - r[j];
        dist[m] = tmp;
        a[m] = i;
        b[m] = j;
        m++;
      }
    }
    init();
    double ans = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    for (int i = 0; i < m; i++) {
      q.push(make_pair(dist[i], i));
    }
    while (!q.empty()) {
      pair<double, int> p = q.top();
      q.pop();
      int i = p.second;
      if (unite(a[i], b[i])) {
        ans += dist[i];
        vis[i] = true;
        for (int j = 0; j < m; j++) {
          if (!vis[j]) {
            q.push(make_pair(dist[j], j));
          }
        }
      }
    }
    printf("%.3f\n", ans);
  }
  return 0;
}
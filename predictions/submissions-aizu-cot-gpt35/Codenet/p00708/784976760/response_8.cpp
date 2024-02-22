#include <cstdio>
#include <vector>

#define N 9999

int parent[N], a[N], b[N];
double node[N];

int root(int a) {
  return parent[a] == a ? a : parent[a] = root(parent[a]);
}

int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}

int main() {
  int n;
  double x, y, z, r;
  
  while (scanf("%d", &n), n) {
    std::vector<std::vector<double>> v;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &x, &y, &z, &r);
      v.push_back({x, y, z, r});
    }

    for (int i = 0; i < n; i++)
      parent[i] = i;

    int m = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double dist_squared = 0.0;
        for (int k = 0; k < 3; k++)
          dist_squared += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        dist_squared -= (v[i][3] + v[j][3]) * (v[i][3] + v[j][3]);
        if (dist_squared <= 0.0)
          unite(i, j);
        else
          node[m++] = dist_squared;
      }
    }

    double x = 0.0;
    for (int i = 0; i < m; i++) {
      int idx = -1;
      double min_dist = 1e9;
      for (int j = 0; j < m; j++) {
        if (node[j] < min_dist && unite(a[j], b[j])) {
          min_dist = node[j];
          idx = j;
        }
      }
      if (idx != -1)
        x += min_dist;
    }

    printf("%.3f\n", x);
  }

  return 0;
}
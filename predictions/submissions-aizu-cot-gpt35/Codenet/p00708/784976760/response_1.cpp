#include <cstdio>
#include <vector>

const int M = 9999;
int parent[M], a[M], b[M];
std::pair<double, int> node[M];

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
  int i, j, k, m, n;
  double x, y, z, r;
  
  while (scanf("%d", &n), n) {
    std::vector<std::vector<double>> v(n, std::vector<double>(4));
    
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);

    for (i = 0; i < n; i++)
      parent[i] = i;

    for (m = i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        double squaredDistance = 0.0;
        for (k = 0; k < 3; k++)
          squaredDistance += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        squaredDistance -= v[i][3] + v[j][3];
        if (squaredDistance <= 0)
          unite(i, j);
        else {
          a[m] = i;
          b[m] = j;
          node[m].first = squaredDistance;
          node[m++].second = m;
        }
      }
    }

    for (x = i = 0; i < m; i++) {
      if (unite(a[node[i].second], b[node[i].second]))
        x += node[i].first;
    }

    printf("%.3f\n", x);
  }
}
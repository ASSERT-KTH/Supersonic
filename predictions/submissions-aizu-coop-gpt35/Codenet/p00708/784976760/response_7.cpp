#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
#define M 9999

int parent[M], a[M], b[M];
pair<double, int> node[M];

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
    vector<vector<double>> v(n, vector<double>(4));
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);

    for (i = 0; i < n; i++)
      parent[i] = i;

    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   greater<pair<double, int>>>
        pq;

    for (m = i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        x = 0;
        for (k = 0; k < 3; k++)
          x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        x -= (v[i][3] + v[j][3]) * (v[i][3] + v[j][3]);
        if (x <= 0)
          unite(i, j);
        else
          pq.push({x, m++});
      }
    }

    double ans = 0.0;

    while (!pq.empty()) {
      double d = pq.top().first;
      int idx = pq.top().second;
      pq.pop();
      if (unite(a[idx], b[idx]))
        ans += sqrt(d);
    }

    printf("%.3f\n", ans);
  }
}
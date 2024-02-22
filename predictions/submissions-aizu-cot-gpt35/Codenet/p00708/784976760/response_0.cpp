#include <cstdio>
#include <cmath>
using namespace std;

#define M 9999

int parent[M], a[M], b[M];
pair<double, int> node[M];

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
    double v_x, v_y, v_z, v_r;
    double x;
    int i, j, k, m;

    vector<vector<double>> v;
    v.reserve(n);

    for (i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &v_x, &v_y, &v_z, &v_r);
      v.emplace_back(v_x, v_y, v_z, v_r);
    }

    for (m = i = 0; i < n; i++) {
      parent[i] = i;
    }

    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        x = 0;
        for (k = 0; k < 3; k++) {
          x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        }
        x = sqrt(x) - v[i][3] - v[j][3];
        if (x <= 0) {
          unite(i, j);
        } else {
          a[m] = i;
          b[m] = j;
          node[m].first = x;
          node[m].second = m;
          m++;
        }
      }
    }

    sort(node, node + m, [](const pair<double, int>& p1, const pair<double, int>& p2) {
      return p1.first < p2.first;
    });

    double result = 0;
    for (i = 0; i < m; i++) {
      if (unite(a[node[i].second], b[node[i].second])) {
        result += node[i].first;
      }
    }

    printf("%.3f\n", result);
  }

  return 0;
}
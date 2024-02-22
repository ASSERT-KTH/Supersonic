#include <array>
#include <cstdio>
#include <vector>

const int M = 9999;

int parent[M], a[M], b[M];
std::array<double, 4> v[M];
std::vector<std::pair<double, std::array<int, 2>>> node;

int root(int a) {
  if (parent[a] == a)
    return a;
  return parent[a] = root(parent[a]);
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
  while (std::scanf("%d", &n), n) {
    std::vector<std::array<double, 4>> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
      std::scanf("%lf%lf%lf%lf", &x, &y, &z, &r);
      v.push_back({x, y, z, r});
    }

    node.clear();
    node.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; i++)
      parent[i] = i;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double x = 0;
        for (int k = 0; k < 3; k++)
          x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        x = std::sqrt(x) - v[i][3] - v[j][3];
        a[m] = i, b[m] = j;
        node.push_back({x, {i, j}});
        if (x <= 0)
          unite(i, j);
      }
    }

    std::make_heap(node.begin(), node.end());

    double x = 0;
    while (!node.empty()) {
      std::pop_heap(node.begin(), node.end());
      auto n = node.back();
      node.pop_back();
      if (unite(a[n.second], b[n.second]))
        x += n.first;
    }

    std::printf("%.3f\n", x);
  }
}
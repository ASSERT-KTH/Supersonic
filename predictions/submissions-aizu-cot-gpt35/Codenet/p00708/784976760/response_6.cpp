#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define M 9999
int parent[M], rank[M];
double a[M], b[M];
struct Node {
  double distance;
  int index;
  bool operator<(const Node& other) const {
    return distance > other.distance;
  }
};
int root(int a) {
  if (parent[a] != a) {
    parent[a] = root(parent[a]);
  }
  return parent[a];
}
void unite(int a, int b) {
  int x = root(a);
  int y = root(b);
  if (x == y) {
    return;
  }
  if (rank[x] < rank[y]) {
    parent[x] = y;
  } else {
    parent[y] = x;
    if (rank[x] == rank[y]) {
      rank[x]++;
    }
  }
}
int main() {
  int i, j, k, m, n;
  double x, y, z, r;
  for (; scanf("%d", &n), n;) {
    vector<double> v(4 * n);
    for (i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &x, &y, &z, &r);
      v[4 * i] = x;
      v[4 * i + 1] = y;
      v[4 * i + 2] = z;
      v[4 * i + 3] = r;
    }
    for (i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
    priority_queue<Node> pq;
    for (m = i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        x = 0;
        for (k = 0; k < 3; k++) {
          x += (v[4 * i + k] - v[4 * j + k]) * (v[4 * i + k] - v[4 * j + k]);
        }
        x = sqrt(x) - v[4 * i + 3] - v[4 * j + 3];
        if (x <= 0) {
          unite(i, j);
        } else {
          a[m] = i;
          b[m] = j;
          pq.push({x, m});
          m++;
        }
      }
    }
    double result = 0;
    while (!pq.empty()) {
      Node node = pq.top();
      pq.pop();
      if (root(a[node.index]) != root(b[node.index])) {
        unite(a[node.index], b[node.index]);
        result += node.distance;
      }
    }
    printf("%.3f\n", result);
  }
}
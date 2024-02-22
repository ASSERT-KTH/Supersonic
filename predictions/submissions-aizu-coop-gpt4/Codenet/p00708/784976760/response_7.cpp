#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define M 9999

struct Sphere {
  double x, y, z, r;
};

struct Node {
  double distance;
  int a, b;
  
  bool operator<(const Node& rhs) const {
    return distance > rhs.distance;
  }
};

int parent[M];

int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }
int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast I/O

  int i, j, n;
  double dist;
  while (scanf("%d", &n), n) {
    vector<Sphere> spheres(n);
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &spheres[i].x, &spheres[i].y, &spheres[i].z, &spheres[i].r);
    for (i = 0; i < n; i++)
      parent[i] = i;
    priority_queue<Node> pq;
    for (i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        dist = sqrt(pow(spheres[i].x - spheres[j].x, 2) + pow(spheres[i].y - spheres[j].y, 2) + pow(spheres[i].z - spheres[j].z, 2)) - spheres[i].r - spheres[j].r;
        if (dist <= 0)
          unite(i, j);
        else
          pq.push({dist, i, j});
      }
    double total = 0.0;
    while (!pq.empty()) {
      Node node = pq.top(); pq.pop();
      if (unite(node.a, node.b))
        total += node.distance;
    }
    printf("%.3f\n", total);
  }
}
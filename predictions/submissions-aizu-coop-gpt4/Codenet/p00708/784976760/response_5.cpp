#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define M 9999
int parent[M], a[M], b[M];
pair<double, int> node[M];

// Use iterative function instead of recursive for finding root
int root(int a) {
  while (parent[a] != a)
    a = parent[a];
  return a;
}

int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}

// Define a structure to store node attributes
struct Node {
  double x, y, z, r;
};

int main() {
  int i, j, m, n;
  double x, y, z, r;
  // Use fast I/O operations
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n, n) {
    vector<Node> v(n);
    for (i = 0; i < n; i++)
      cin >> v[i].x >> v[i].y >> v[i].z >> v[i].r;
    for (i = 0; i < n; i++)
      parent[i] = i;
    priority_queue<pair<double, int>> pq;
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        x = sqrt((v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y) +
                 (v[i].z - v[j].z) * (v[i].z - v[j].z)) -
            v[i].r - v[j].r;
        if (x <= 0)
          unite(i, j);
        else
          pq.push({-x, m}), a[m] = i, b[m] = j, m++;
      }
    x = 0;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      if (unite(a[p.second], b[p.second]))
        x -= p.first;
    }
    printf("%.3f\n", x);
  }
}
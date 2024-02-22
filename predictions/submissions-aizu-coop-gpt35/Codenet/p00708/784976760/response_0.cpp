#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n;
  double x, y, z, r;
  while (scanf("%d", &n), n) {
    vector<vector<double>> v(n, vector<double>(4)); // Dynamically allocate memory for input nodes
    for (int i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);

    vector<int> parent(n); // Dynamically allocate memory for parent array
    for (int i = 0; i < n; i++)
      parent[i] = i;

    vector<pair<double, pair<int, int>>> edges; // Store edges with their distances

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double dist = 0.0;
        for (int k = 0; k < 3; k++)
          dist += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        dist = sqrt(dist) - v[i][3] - v[j][3];
        if (dist <= 0) {
          int a = i, b = j;
          while (a != parent[a])
            a = parent[a];
          while (b != parent[b])
            b = parent[b];
          parent[a] = b;
        } else {
          edges.push_back({dist, {i, j}});
        }
      }
    }

    sort(edges.begin(), edges.end());

    double totalWeight = 0.0;
    for (auto edge : edges) {
      int a = edge.second.first, b = edge.second.second;
      while (a != parent[a])
        a = parent[a];
      while (b != parent[b])
        b = parent[b];
      if (a != b) {
        parent[a] = b;
        totalWeight += edge.first;
      }
    }

    printf("%.3f\n", totalWeight);
  }
}
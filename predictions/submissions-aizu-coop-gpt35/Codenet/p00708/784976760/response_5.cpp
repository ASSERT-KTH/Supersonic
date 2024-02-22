#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int i, j, k, m, n;
  double x, y, z, r;

  while (scanf("%d", &n), n) {
    vector<vector<double>> v;
    vector<int> parent(n);
    vector<pair<double, int>> node;
    
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &x, &y, &z, &r), v.push_back({x, y, z, r});
    
    for (i = 0; i < n; i++)
      parent[i] = i;
    
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        double squaredDist = 0.0;
        for (k = 0; k < 3; k++)
          squaredDist += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);

        double dist = sqrt(squaredDist) - v[i][3] - v[j][3];
        if (dist <= 0)
          parent[i] = parent[j] = min(parent[i], parent[j]);
        else
          node.push_back({dist, i * n + j});
      }
    }

    sort(node.begin(), node.end());

    double totalWeight = 0.0;
    for (i = 0; i < node.size(); i++) {
      int a = node[i].second / n;
      int b = node[i].second % n;
      if (parent[a] != parent[b]) {
        int rootA = parent[a];
        int rootB = parent[b];
        for (j = 0; j < n; j++) {
          if (parent[j] == rootA)
            parent[j] = rootB;
        }
        totalWeight += node[i].first;
      }
    }

    printf("%.3f\n", totalWeight);
  }
}
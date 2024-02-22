#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct Edge {
  int u, v;
  double weight;
};

#define M 9999

vector<int> parent(M);
vector<Edge> edges(M);
vector<pair<double, int>> sortedEdges(M);

int find(int node) {
  if (parent[node] != node) {
    parent[node] = find(parent[node]);
  }
  return parent[node];
}

void unite(int a, int b) {
  int x = find(a);
  int y = find(b);
  parent[x] = y;
}

int main() {
  int n;
  while (scanf("%d", &n), n) {
    vector<vector<double>> v(n, vector<double>(4));
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
    }

    int m = 0;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      for (int j = i + 1; j < n; j++) {
        double dist = sqrt(pow(v[i][0] - v[j][0], 2) +
                           pow(v[i][1] - v[j][1], 2) +
                           pow(v[i][2] - v[j][2], 2)) -
                      v[i][3] - v[j][3];

        if (dist <= 0) {
          unite(i, j);
        } else {
          edges[m] = {i, j, dist};
          sortedEdges[m] = {dist, m};
          m++;
        }
      }
    }

    sort(sortedEdges.begin(), sortedEdges.begin() + m);

    double totalWeight = 0;
    for (int i = 0; i < m; i++) {
      int u = edges[sortedEdges[i].second].u;
      int v = edges[sortedEdges[i].second].v;
      double weight = edges[sortedEdges[i].second].weight;

      if (find(u) != find(v)) {
        unite(u, v);
        totalWeight += weight;
      }
    }

    printf("%.3f\n", totalWeight);
  }
  return 0;
}
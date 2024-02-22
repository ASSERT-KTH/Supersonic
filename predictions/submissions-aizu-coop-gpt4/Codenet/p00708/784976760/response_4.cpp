#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

constexpr int M = 9999;
array<int, M> parent, rank, a, b;
array<pair<double, int>, M> node;

int root(int a) {
  if (parent[a] != a) {
    parent[a] = root(parent[a]);
  }
  return parent[a];
}

bool unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y) {
    return false;
  }
  if (rank[x] < rank[y]) {
    parent[x] = y;
  } else {
    parent[y] = x;
    if (rank[x] == rank[y]) {
      ++rank[x];
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n, n) {
    vector<vector<double>> v(n, vector<double>(4));
    for (auto &ve : v) {
      cin >> ve[0] >> ve[1] >> ve[2] >> ve[3];
    }
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
    int m = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        double x = 0;
        for (int k = 0; k < 3; ++k) {
          x += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        }
        x = sqrt(x) - v[i][3] - v[j][3];
        if (x <= 0) {
          unite(i, j);
        } else {
          a[m] = i, b[m] = j, node[m].first = x, node[m++].second = m;
        }
      }
    }
    sort(node.begin(), node.begin() + m);
    double x = 0;
    for (int i = 0; i < m; ++i) {
      if (unite(a[node[i].second], b[node[i].second])) {
        x += node[i].first;
      }
    }
    cout << fixed << setprecision(3) << x << '\n';
  }
}
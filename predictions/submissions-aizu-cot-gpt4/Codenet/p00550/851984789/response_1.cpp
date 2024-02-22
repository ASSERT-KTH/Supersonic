#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  vector<vector<pair<int, int>>> x(n+1), y(n+1);
  vector<int> dist(n+1, 999999), T(n+1), U(n+1);
  vector<bool> used(m);
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[i] = {a, b};
    x[a].push_back({b, i});
    x[b].push_back({a, i});
  }
  dist[1] = 0;
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop();
    for (pair<int, int> i : x[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push(i.first);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> j : x[i]) {
      y[i].push_back(j);
      T[j.first]++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < q; i++) {
    int c;
    scanf("%d", &c);
    c--;
    queue<pair<int, int>> Q1;
    int ss = dist[edges[c].first] > dist[edges[c].second] ? edges[c].first : edges[c].second;
    if (ss >= 1 && U[ss] == 0 && !used[c]) {
      Q1.push({ss, c});
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop();
        if (U[a1] == 1 || used[a2])
          continue;
        T[a1]--;
        used[a2] = true;
        if (T[a1] != 0)
          continue;
        cnt++;
        U[a1] = 1;
        for (pair<int, int> j : y[a1]) {
          if (U[j.first] == 0)
            Q1.push(j);
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
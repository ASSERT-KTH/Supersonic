#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int n, q;
vector<vector<pair<int, int>>> x, y;
vector<int> a, dist;
unordered_map<int, int> T, U;
unordered_set<int> used;

int main() {
  cin >> n >> q;

  x.resize(n + 1);
  y.resize(n + 1);
  dist.resize(n + 1, 999999);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    x[u].emplace_back(v, i);
    x[v].emplace_back(u, i);
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
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    c--;
    queue<pair<int, int>> Q1;
    int ss = -1;
    if (dist[a[c]] < dist[b[c]])
      ss = b[c];
    if (dist[a[c]] > dist[b[c]])
      ss = a[c];
    if (ss >= 1 && U[ss] == 0 && used.find(c) == used.end()) {
      Q1.push(make_pair(ss, c));
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop();
        if (U[a1] == 1 || used.find(a2) != used.end())
          continue;
        T[a1]--;
        used.insert(a2);
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
    cout << cnt << endl;
  }

  return 0;
}
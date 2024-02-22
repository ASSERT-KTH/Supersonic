#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, q, c, cnt;
vector<int> a, b, dist, T, U;
vector<vector<pair<int, int>>> x, y;
vector<bool> used;

int main() {
  cin >> n >> m >> q;

  a.resize(m);
  b.resize(m);
  x.resize(n + 1);
  dist.resize(n + 1, 999999);
  T.resize(n + 1);
  U.resize(n + 1);
  used.resize(q);

  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    x[a[i]].emplace_back(b[i], i);
    x[b[i]].emplace_back(a[i], i);
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

  y.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }

  for (int i = 0; i < q; i++) {
    cin >> c;
    c--;
    queue<pair<int, int>> Q1;
    int ss = -1;
    if (dist[a[c]] < dist[b[c]])
      ss = b[c];
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.emplace(ss, c);
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop();
        if (U[a1] == 1)
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
    cout << cnt << endl;
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(m), b(m);
  vector<vector<pair<int, int>>> x(n+1), y(n+1);
  vector<bool> used(m, false);
  vector<int> dist(n+1, 999999), T(n+1, 0), U(n+1, 0);
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    x[a[i]].push_back(make_pair(b[i], i));
    x[b[i]].push_back(make_pair(a[i], i));
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
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.push(make_pair(ss, c));
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop();
        if (U[a1] == 1 || used[a2] == true)
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
    cout << cnt << '\n';
  }
  return 0;
}
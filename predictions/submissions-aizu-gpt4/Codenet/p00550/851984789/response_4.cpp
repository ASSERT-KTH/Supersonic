#include <bits/stdc++.h>
using namespace std;
const int MAX = 210000;
int n, m, q, a[MAX], b[MAX], c, dist[MAX], T[MAX], cnt, U[MAX];
vector<pair<int, int>> adj[MAX], y[MAX];
bool used[MAX];
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    adj[a[i]].emplace_back(b[i], i);
    adj[b[i]].emplace_back(a[i], i);
  }
  fill(dist, dist + n + 1, MAX);
  dist[1] = 0;
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop();
    for (auto& i : adj[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push(i.first);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto& j : adj[i]) {
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
    if (dist[a[c]] > dist[b[c]])
      ss = a[c];
    if (ss >= 1 && U[ss] == 0 && !used[c]) {
      Q1.emplace(ss, c);
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
        for (auto& j : y[a1]) {
          if (U[j.first] == 0)
            Q1.push(j);
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
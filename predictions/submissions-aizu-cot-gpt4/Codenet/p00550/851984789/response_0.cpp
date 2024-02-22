#include <bits/stdc++.h>
using namespace std;
int n, m, q, a[210000], b[210000], c, dist[110000], T[110000], cnt, U[110000];
vector<pair<int, int>> x[110000], y[110000];
bool used[210000];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    x[a[i]].emplace_back(b[i], i);
    x[b[i]].emplace_back(a[i], i);
  }
  fill(dist, dist + n + 1, 999999);
  dist[1] = 0;
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    for (pair<int, int> i : x[Q.front()]) {
      if (dist[i.first] > dist[Q.front()] + 1) {
        dist[i.first] = dist[Q.front()] + 1;
        Q.push(i.first);
      }
    }
    Q.pop();
  }
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].emplace_back(j);
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
    if (ss >= 1 && !U[ss] && !used[c]) {
      Q1.emplace(ss, c);
      while (!Q1.empty()) {
        if (!U[Q1.front().first] && !used[Q1.front().second]) {
          T[Q1.front().first]--;
          used[Q1.front().second] = true;
          if (!T[Q1.front().first]) {
            cnt++;
            U[Q1.front().first] = 1;
            for (pair<int, int> j : y[Q1.front().first]) {
              if (!U[j.first])
                Q1.push(j);
            }
          }
        }
        Q1.pop();
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
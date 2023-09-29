#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 110000;
int a[210000], b[210000], dist[MAX_N], T[MAX_N], U[MAX_N];
vector<int> x[MAX_N], y[MAX_N];
bool used[210000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q, cnt = 0;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    x[a[i]].push_back(i);
    x[b[i]].push_back(i);
  }
  fill(dist, dist + n + 1, INT_MAX);
  dist[1] = 0;
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop();
    for (int i : x[a1]) {
      int b1 = a[i] ^ b[i] ^ a1;
      if (dist[b1] > dist[a1] + 1) {
        dist[b1] = dist[a1] + 1;
        Q.push(b1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j : x[i]) {
      int b1 = a[j] ^ b[j] ^ i;
      if (dist[i] < dist[b1]) {
        y[i].push_back(j);
        T[b1]++;
      }
    }
  }
  while (q--) {
    int c;
    cin >> c;
    c--;
    int ss = dist[a[c]] > dist[b[c]] ? a[c] : dist[a[c]] < dist[b[c]] ? b[c] : -1;
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      queue<pair<int, int>> Q1;
      Q1.push({ss, c});
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop();
        if (U[a1] || used[a2])
          continue;
        T[a1]--;
        used[a2] = true;
        if (T[a1] != 0)
          continue;
        cnt++;
        U[a1] = 1;
        for (int j : y[a1]) {
          if (U[a[j] ^ b[j] ^ a1] == 0)
            Q1.push({a1 ^ a[j] ^ b[j], j});
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
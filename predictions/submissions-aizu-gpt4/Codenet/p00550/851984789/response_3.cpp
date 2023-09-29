#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
int a[N], b[N], dist[N], T[N], U[N];
vector<int> x[N], y[N];
bool used[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    x[a[i]].push_back(b[i]);
    x[b[i]].push_back(a[i]);
  }
  fill(dist, dist + n + 1, N);
  dist[1] = 0;
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop();
    for (int i: x[a1]) {
      if (dist[i] > dist[a1] + 1) {
        dist[i] = dist[a1] + 1;
        Q.push(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j: x[i]) {
      if (dist[i] < dist[j]) {
        y[i].push_back(j);
        T[j]++;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    c--;
    queue<int> Q1;
    int ss = dist[a[c]] < dist[b[c]] ? b[c] : a[c];
    if (ss >= 1 && U[ss] == 0 && !used[c]) {
      Q1.push(ss);
      while (!Q1.empty()) {
        int a1 = Q1.front();
        Q1.pop();
        if (U[a1] == 1 || used[c])
          continue;
        T[a1]--;
        used[c] = true;
        if (T[a1] != 0)
          continue;
        cnt++;
        U[a1] = 1;
        for (int j: y[a1]) {
          if (U[j] == 0)
            Q1.push(j);
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
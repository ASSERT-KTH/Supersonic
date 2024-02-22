#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void reader(int *x) {
  cin >> *x;
}

void bfs(int u, vector<int> E[], int d[], bool ok[], int &cnt, bool t) {
  queue<int> que;
  que.push(u);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (int v : E[p]) {
      if (t) {
        if (d[v] > d[p] && !ok[v]) {
          ok[v] = 1;
          cnt++;
          que.push(v);
        }
      } else if (d[v] == -1) {
        d[v] = d[p] + 1;
        que.push(v);
      }
    }
  }
}

int main() {
  int n, m, q;
  reader(&n);
  reader(&m);
  reader(&q);
  vector<int> E[n];
  int u[m], v[m], r[q], ans[q], d[n], cnt = 1;
  bool b[m] = {}, ok[n] = {};
  for (int i = 0; i < m; i++) {
    reader(&u[i]);
    reader(&v[i]);
    u[i]--;
    v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  fill(d, d + n, -1);
  d[0] = 0;
  bfs(0, E, d, ok, cnt, 0);
  for (int i = 0; i < m; i++) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  for (int i = 0; i < n; i++) E[i].clear();
  for (int i = 0; i < q; i++) {
    reader(&r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  ok[0] = true;
  for (int i = 0; i < m; i++) {
    if (!b[i]) {
      if (d[v[i]] - d[u[i]] == 1) {
        E[u[i]].emplace_back(v[i]);
      }
    }
  }
  bfs(0, E, d, ok, cnt, 1);
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E[u[r[i]]].emplace_back(v[r[i]]);
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs(v[r[i]], E, d, ok, cnt, 1);
      }
    }
  }
  for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}
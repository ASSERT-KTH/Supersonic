#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5, MAXM = 2e5 + 5, MAXQ = 2e5 + 5;
int n, m, q, cnt = 1;
int u[MAXM], v[MAXM], r[MAXQ], ans[MAXQ], d[MAXN];
bool b[MAXM], ok[MAXN];
vector<int> E[MAXN];
void bfs(int u, int t) {
  queue<int> que;
  que.push(u);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (int v : E[p]) {
      if (t) {
        if (d[v] > d[p] && !ok[v]) {
          ok[v] = true;
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
void reader(int &x) {
  int k = getchar_unlocked();
  x = k - '0';
  while (1) {
    k = getchar_unlocked();
    if (k < '0' || k > '9')
      break;
    x = ((x) << 1) + ((x) << 3) + k - '0';
  }
}
int main() {
  memset(d, -1, sizeof(d));
  d[0] = 0;
  reader(n);
  reader(m);
  reader(q);
  for (int i = 0; i < m; i++) {
    reader(u[i]);
    reader(v[i]);
    u[i]--;
    v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  bfs(0, 0);
  for (int i = 0; i < m; i++) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  for (int i = 0; i < n; i++) E[i].clear();
  for (int i = 0; i < q; i++) {
    reader(r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  ok[0] = true;
  for (int i = 0; i < m; i++) {
    if (!b[i] && d[v[i]] - d[u[i]] == 1) {
      E[u[i]].push_back(v[i]);
    }
  }
  bfs(0, 1);
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E[u[r[i]]].push_back(v[r[i]]);
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs(v[r[i]], 1);
      }
    }
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
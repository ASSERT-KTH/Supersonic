#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
bool E[100000][100000];
int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;
bool b[200000], ok[100000];
queue<int> que;
void bfs(int u, int t) {
  que.push(u);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (int v = 0; v < 100000; v++) {
      if (E[p][v]) {
        if (t) {
          if (d[v] > d[p]) {
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
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  rep(i, m) {
    scanf("%d%d", &u[i], &v[i]);
    u[i]--;
    v[i]--;
    E[u[i]][v[i]] = true;
    E[v[i]][u[i]] = true;
  }
  memset(d, -1, sizeof(d));
  d[0] = 0;
  bfs(0, 0);
  rep(i, m) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  memset(E, 0, sizeof(E));
  rep(i, q) {
    scanf("%d", &r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  ok[0] = true;
  rep(i, m) {
    if (!b[i]) {
      if (d[v[i]] - d[u[i]] == 1) {
        E[u[i]][v[i]] = true;
      }
    }
  }
  bfs(0, 1);
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E[u[r[i]]][v[r[i]]] = true;
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs(v[r[i]], 1);
      }
    }
  }
  rep(i, q) printf("%d\n", ans[i]);
}
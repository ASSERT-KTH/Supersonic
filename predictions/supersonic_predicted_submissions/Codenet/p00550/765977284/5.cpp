#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
void reader(int *x) {
  int k = getchar_unlocked();
  *x = k - '0';
  while (1) {
    k = getchar_unlocked();
    if (k < '0' || k > '9')
      break;
    *x = ((*x) << 1) + ((*x) << 3) + k - '0';
  }
}
vector<int> E[100000];
int u[200005], v[200005], r[200005], ans[200005], d[100000], cnt = 1;
bool b[200005], ok[100000];
queue<int> que;
void bfs(int u, int t) {
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
      } else if (!~d[v]) {
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
  rep(i, m) {
    reader(&u[i]);
    reader(&v[i]);
    u[i]--;
    v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  queue<int> que;
  memset(d, -1, sizeof(d));
  d[0] = 0;
  bfs(0, 0);
  rep(i, m) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  rep(i, n) E[i].clear();
  rep(i, q) {
    reader(&r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  ok[0] = true;
  rep(i, m) {
    if (!b[i]) {
      if (d[v[i]] - d[u[i]] == 1) {
        E[u[i]].emplace_back(v[i]);
      }
    }
  }
  bfs(0, 1);
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E[u[r[i]]].emplace_back(v[r[i]]);
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs(v[r[i]], 1);
      }
    }
  }
  rep(i, q) printf("%d\n", ans[i]);
}

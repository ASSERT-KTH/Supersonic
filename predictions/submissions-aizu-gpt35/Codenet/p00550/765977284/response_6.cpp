#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
const int MAXN = 100005;
vector<int> E[MAXN];
int u[200005], v[200005], r[200005], ans[200005], d[MAXN], cnt = 1;
bool b[200005], ok[MAXN];
queue<int> que;
void bfs(int s, int t) {
  memset(d, -1, sizeof(d));
  d[s] = 0;
  que.push(s);
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
  scanf("%d%d%d", &n, &m, &q);
  rep(i, m) {
    scanf("%d%d", &u[i], &v[i]);
    u[i]--, v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  rep(i, q) {
    scanf("%d", &r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  bfs(0, 0);
  rep(i, m) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  rep(i, n) E[i].clear();
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
  return 0;
}
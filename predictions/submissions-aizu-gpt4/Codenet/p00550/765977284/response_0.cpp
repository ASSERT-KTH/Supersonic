#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100000;
const int MAXM = 200000;

vector<int> E[MAXN];
int u[MAXM], v[MAXM], r[MAXM], ans[MAXM], d[MAXN];
bool b[MAXM], ok[MAXN];
queue<int> que;
int cnt = 1;

void reader(int &x) {
  x = 0;
  char ch = getchar_unlocked();
  while(ch < '0' || ch > '9') ch = getchar_unlocked();
  while(ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar_unlocked();
  }
}

void bfs(int s, bool add) {
  que.push(s);
  while (!que.empty()) {
    int u = que.front(); que.pop();
    for (auto v : E[u]) {
      if (add) {
        if (d[v] > d[u] && !ok[v]) {
          ok[v] = 1;
          cnt++;
          que.push(v);
        }
      } else if (d[v] == -1) {
        d[v] = d[u] + 1;
        que.push(v);
      }
    }
  }
}

int main() {
  int n, m, q;
  reader(n); reader(m); reader(q);
  for (int i = 0; i < m; i++) {
    reader(u[i]); reader(v[i]); u[i]--; v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  memset(d, -1, sizeof(d));
  d[0] = 0;
  bfs(0, false);
  for (int i = 0; i < m; i++) {
    if (d[u[i]] > d[v[i]]) swap(u[i], v[i]);
  }
  for (int i = 0; i < n; i++) E[i].clear();
  for (int i = 0; i < q; i++) {
    reader(r[i]); r[i]--;
    b[r[i]] = true;
  }
  ok[0] = true;
  for (int i = 0; i < m; i++) {
    if (!b[i] && d[v[i]] - d[u[i]] == 1) E[u[i]].push_back(v[i]);
  }
  bfs(0, true);
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E[u[r[i]]].push_back(v[r[i]]);
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs(v[r[i]], true);
      }
    }
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
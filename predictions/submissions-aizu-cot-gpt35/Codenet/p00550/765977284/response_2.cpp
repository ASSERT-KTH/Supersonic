#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void reader(int *x) {
  scanf("%d", x);
}

vector<int> E[100000];
int u[100000], v[100000], r[100000], ans[100000], d[100000], cnt = 1;
bool b[100000], ok[100000];
queue<int> que;

void bfs(int u, int t) {
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
    if (t && cnt == 100000) break; // Optimization: break when required condition is met
  }
}

int main() {
  int n, m, q;
  reader(&n);
  reader(&m);
  reader(&q);
  for (int i = 0; i < m; i++) {
    reader(&u[i]);
    reader(&v[i]);
    u[i]--;
    v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  memset(d, -1, sizeof(d));
  d[0] = 0;
  bfs(0, 0);
  for (int i = 0; i < m; i++) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  for (int i = 0; i < q; i++) {
    reader(&r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  ok[0] = true;
  for (int i = 0; i < m; i++) {
    if (!b[i]) {
      if (d[v[i]] - d[u[i]] == 1) {
        E[u[i]].push_back(v[i]);
      }
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
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
}
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

void reader(int *x) {
  scanf("%d", x);
}

const int MAX_N = 100000;
const int MAX_M = 200000;
const int MAX_Q = 200000;

std::vector<int> E[MAX_N];
int u[MAX_M], v[MAX_M], r[MAX_Q], ans[MAX_Q], d[MAX_N], cnt = 1;
bool visited[MAX_N];

void bfs(int start, int q) {
  std::queue<int> que;
  que.push(start);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (int i = 0; i < E[p].size(); i++) {
      int v = E[p][i];
      if (q) {
        if (d[v] > d[p] && !visited[v]) {
          visited[v] = true;
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
      std::swap(u[i], v[i]);
  }

  for (int i = 0; i < n; i++)
    E[i].clear();

  for (int i = 0; i < q; i++) {
    reader(&r[i]);
    r[i]--;
    visited[r[i]] = true;
  }

  visited[0] = true;
  for (int i = 0; i < m; i++) {
    if (!visited[i]) {
      if (d[v[i]] - d[u[i]] == 1) {
        E[u[i]].emplace_back(v[i]);
      }
    }
  }

  bfs(0, 1);

  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !visited[v[r[i]]]) {
      E[u[r[i]]].emplace_back(v[r[i]]);
      if (visited[u[r[i]]]) {
        cnt++;
        visited[v[r[i]]] = true;
        bfs(v[r[i]], 1);
      }
    }
  }

  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
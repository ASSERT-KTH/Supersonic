#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)

std::vector<int> E[100000];
int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;
bool b[200000], ok[100000];
std::queue<int> que;

void bfs(int u, bool t) {
  que.push(u);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (const int &v : E[p]) {
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
  std::cin >> n >> m >> q;
  rep(i, m) {
    std::cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }

  memset(d, -1, sizeof(d));
  d[0] = 0;
  bfs(0, false);

  rep(i, m) {
    if (d[u[i]] > d[v[i]])
      std::swap(u[i], v[i]);
  }

  rep(i, n) E[i].clear();

  rep(i, q) {
    std::cin >> r[i];
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

  bfs(0, true);

  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E[u[r[i]]].emplace_back(v[r[i]]);
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs(v[r[i]], true);
      }
    }
  }

  rep(i, q) std::cout << ans[i] << std::endl;

  return 0;
}
#include <iostream>
#include <vector>
#include <deque>

void reader(int *x) {
  int k = getchar();
  *x = k - '0';
  while (1) {
    k = getchar();
    if (k < '0' || k > '9')
      break;
    *x = ((*x) << 1) + ((*x) << 3) + k - '0';
  }
}

std::vector<int> E[100000];
int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;
std::vector<bool> ok(100000);

void bfs(int u, int t) {
  std::deque<int> que;
  que.push_back(u);
  while (!que.empty()) {
    int p = que.front();
    que.pop_front();
    for (int v : E[p]) {
      if (t) {
        if (d[v] > d[p] && !ok[v]) {
          ok[v] = true;
          cnt++;
          que.push_back(v);
        }
      } else if (d[v] == -1) {
        d[v] = d[p] + 1;
        que.push_back(v);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

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

  d[0] = 0;
  bfs(0, 0);

  for (int i = 0; i < m; i++) {
    if (d[u[i]] > d[v[i]])
      std::swap(u[i], v[i]);
  }

  for (int i = 0; i < q; i++) {
    reader(&r[i]);
    r[i]--;
    ok[r[i]] = true;
  }

  for (int i = 0; i < m; i++) {
    if (!ok[i]) {
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

  for (int i = 0; i < q; i++) {
    std::cout << ans[i] << '\n';
  }

  return 0;
}
#include <iostream>
#include <vector>

void reader(int& x) {
  scanf("%d", &x);
}

std::vector<int> E;
std::vector<int> u, v, r, ans, d;
std::vector<bool> b, ok;
std::vector<int> que;
int cnt;

void bfs(int u, int t) {
  que.push_back(u);
  while (!que.empty()) {
    int p = que.front();
    que.erase(que.begin());
    for (int i = 0; i < E.size(); ++i) {
      int v = E[i];
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
  int n, m, q;
  reader(n);
  reader(m);
  reader(q);

  u.resize(m);
  v.resize(m);
  r.resize(q);
  b.resize(m);
  ans.resize(q);
  d.resize(n, -1);
  ok.resize(n, false);

  for (int i = 0; i < m; ++i) {
    reader(u[i]);
    reader(v[i]);
    u[i]--;
    v[i]--;
    E.push_back(i);
    E.push_back(i + m);
  }

  d[0] = 0;
  cnt = 1;
  bfs(0, 0);

  for (int i = 0; i < m; ++i) {
    if (d[u[i]] > d[v[i]]) {
      std::swap(u[i], v[i]);
    }
  }

  E.clear();

  for (int i = 0; i < q; ++i) {
    reader(r[i]);
    r[i]--;
    b[r[i]] = true;
  }

  ok[0] = true;

  for (int i = 0; i < m; ++i) {
    if (!b[i]) {
      if (d[v[i]] - d[u[i]] == 1) {
        E.push_back(i);
      }
    }
  }

  cnt = 1;
  bfs(0, 1);

  for (int i = q - 1; i >= 0; --i) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E.push_back(r[i]);
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs(v[r[i]], 1);
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    std::cout << ans[i] << std::endl;
  }

  return 0;
}
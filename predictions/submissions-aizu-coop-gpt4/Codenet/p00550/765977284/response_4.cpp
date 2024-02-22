#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

// Use std::array instead of C-style arrays
array<int, 200000> u, v, r, ans;
array<int, 100000> d;
array<bool, 200000> b;
array<bool, 100000> ok;
vector<vector<int>> E(100000);
int cnt = 1;

// Use std::deque instead of std::queue for better performance
deque<int> que;

void bfs1(int u) {
  que.push_back(u);
  while (!que.empty()) {
    int p = que.front();
    que.pop_front();
    for (int v : E[p]) {
      if (d[v] == -1) {
        d[v] = d[p] + 1;
        que.push_back(v);
      }
    }
  }
}

void bfs2(int u) {
  que.push_back(u);
  while (!que.empty()) {
    int p = que.front();
    que.pop_front();
    for (int v : E[p]) {
      if (d[v] > d[p] && !ok[v]) {
        ok[v] = true;
        cnt++;
        que.push_back(v);
      }
    }
  }
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  rep(i, m) {
    scanf("%d %d", &u[i], &v[i]);
    u[i]--;
    v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  
  fill(d.begin(), d.end(), -1);
  d[0] = 0;
  bfs1(0);
  
  rep(i, m) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  
  rep(i, n) E[i].clear();
  
  rep(i, q) {
    scanf("%d", &r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  
  ok[0] = true;
  
  rep(i, m) {
    if (!b[i]) {
      if (d[v[i]] - d[u[i]] == 1) {
        E[u[i]].push_back(v[i]);
      }
    }
  }
  
  bfs2(0);
  
  stringstream output;
  
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E[u[r[i]]].push_back(v[r[i]]);
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs2(v[r[i]]);
      }
    }
    output << ans[i] << '\n';
  }
  
  cout << output.str();
}
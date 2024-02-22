#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;
bool b[200000], ok[100000];

void bfs(vector<int>* E, queue<int>& que, int u, int t) {
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
      } else if (d[v] == -1) {
        d[v] = d[p] + 1;
        que.push(v);
      }
    }
  }
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> E[100000];
  queue<int> que;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  
  for (int i = 0; i < n; i++) {
    d[i] = -1;
  }
  d[0] = 0;
  
  bfs(E, que, 0, 0);
  
  for (int i = 0; i < m; i++) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  
  for (int i = 0; i < n; i++) {
    E[i].clear();
  }
  
  for (int i = 0; i < q; i++) {
    cin >> r[i];
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
  
  bfs(E, que, 0, 1);
  
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
      E[u[r[i]]].push_back(v[r[i]]);
      if (ok[u[r[i]]]) {
        cnt++;
        ok[v[r[i]]] = true;
        bfs(E, que, v[r[i]], 1);
      }
    }
  }
  
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
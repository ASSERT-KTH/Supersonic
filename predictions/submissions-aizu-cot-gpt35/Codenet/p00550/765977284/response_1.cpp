#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

void reader(int& x) {
  cin >> x;
}

vector<int> E[100000];
vector<int> u, v, r, ans;
int d[100000], cnt = 1;
bool b[200000];
queue<int> que;

void bfs(int src, int t) {
  que.push(src);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (int i = 0; i < E[p].size(); i++) {
      int v = E[p][i];
      if ((t && d[v] > d[p]) || (!t && d[v] == -1)) {
        d[v] = d[p] + 1;
        que.push(v);
        if (!t) cnt++;
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
  
  for (int i = 0; i < m; i++) {
    reader(u[i]);
    reader(v[i]);
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
  
  r.resize(q);
  ans.resize(q);
  
  for (int i = 0; i < q; i++) {
    reader(r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  
  for (int i = 0; i < m; i++) {
    if (!b[i] && d[v[i]] - d[u[i]] == 1) {
      E[u[i]].emplace_back(v[i]);
    }
  }
  
  bfs(0, 1);
  
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && d[u[r[i]]] == d[v[r[i]]] - 1) {
      E[u[r[i]]].emplace_back(v[r[i]]);
      if (d[v[r[i]]] == d[u[r[i]]] + 1) {
        cnt++;
        bfs(v[r[i]], 1);
      }
    }
  }
  
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}
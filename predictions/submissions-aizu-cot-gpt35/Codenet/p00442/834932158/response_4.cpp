#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> deg(n), ans;
  vector<vector<int>> G(n);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].emplace_back(y);
    deg[y]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ans.emplace_back(v);
    for (int u : G[v]) {
      if (--deg[u] == 0)
        q.push(u);
    }
  }

  copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, "\n"));

  int res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (find(G[ans[i]].begin(), G[ans[i]].end(), ans[i + 1]) == G[ans[i]].end())
      res = 0;
  }

  cout << (res == 1 ? 0 : 1) << endl;

  return 0;
}
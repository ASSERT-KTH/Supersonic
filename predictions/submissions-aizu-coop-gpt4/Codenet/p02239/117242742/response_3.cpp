#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector<vector<int>> g;
vector<int> d;
vector<bool> v;
void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto i: g[u]) {
      if (!v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        q.push(i);
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  g.resize(n);
  d.resize(n, INT_MAX);
  v.resize(n, false);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    u--; // zero-based index
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--; // zero-based index
      g[u].push_back(v);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << ((d[i] == INT_MAX) ? -1 : d[i]) << endl;
  return 0;
}
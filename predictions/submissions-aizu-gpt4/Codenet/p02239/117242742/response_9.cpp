#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> m;
vector<int> v, d;
int n;
void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i : m[u]) {
      if (!v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        q.push(i);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  m.resize(n);
  v.assign(n, false);
  d.assign(n, -1);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      m[u].push_back(v - 1);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << "\n";
  return 0;
}
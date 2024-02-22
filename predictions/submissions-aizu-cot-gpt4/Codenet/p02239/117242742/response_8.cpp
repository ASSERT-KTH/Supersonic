#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> m;
vector<int> v, d;

void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < m[u].size(); i++) {
      if (m[u][i] && !v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  m.resize(n);
  v.resize(n);
  d.resize(n, -1);

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    m[u - 1].reserve(k);
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      m[u - 1][v - 1] = true;
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << '\n';
  return 0;
}
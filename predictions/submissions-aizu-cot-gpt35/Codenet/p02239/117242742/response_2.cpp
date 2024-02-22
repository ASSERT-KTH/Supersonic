#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int s, vector<bool>& v, vector<int>& d, vector<vector<int>>& adj) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int next = adj[u][i];
      if (!v[next]) {
        d[next] = d[u] + 1;
        v[next] = true;
        q.push(next);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<bool> v(n, false);
  vector<int> d(n, -1);
  vector<vector<int>> adj(n);

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int next;
      cin >> next;
      adj[u - 1].push_back(next - 1);
    }
  }

  bfs(0, v, d, adj);

  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << d[i] << endl;
  }

  return 0;
}
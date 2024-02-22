#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[105], d(105), v(105);
void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int node = adj[u][i];
      if (!v[node]) {
        d[node] = d[u] + 1;
        v[node] = true;
        q.push(node);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false); //Fast I/O
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      adj[u - 1].push_back(v - 1);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << "\n";
  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v, d;
vector<vector<int>> adj_list;
void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj_list[u].size(); i++) {
      int node = adj_list[u][i];
      if (!v[node]) {
        d[node] = d[u] + 1;
        v[node] = true;
        q.push(node);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  v.resize(n, false);
  d.resize(n, -1);
  adj_list.resize(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      adj_list[u].push_back(v);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << endl;
  return 0;
}
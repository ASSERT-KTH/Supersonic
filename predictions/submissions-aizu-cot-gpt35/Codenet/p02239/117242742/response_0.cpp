#include <iostream>
#include <vector>
#include <queue>

int n;
std::vector<std::vector<int>> adj;
std::vector<int> d;

void bfs(int s) {
  std::vector<bool> v(n, false);
  v[s] = true;
  d[s] = 0;
  std::queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i : adj[u]) {
      if (!v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  std::cin >> n;
  adj.resize(n);
  d.resize(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    std::cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int temp;
      std::cin >> temp;
      adj[u - 1].push_back(temp - 1);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    std::cout << i + 1 << ' ' << d[i] << '\n';
  return 0;
}
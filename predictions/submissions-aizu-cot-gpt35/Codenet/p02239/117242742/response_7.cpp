#include <iostream>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>>& m, std::vector<int>& d, std::vector<bool>& v, int& s) {
  v[s] = true;
  d[s] = 0;
  std::queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < m.size(); i++) {
      if (m[u][i] && !v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  
  std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
  std::vector<int> d(n, -1);
  std::vector<bool> v(n, false);

  for (int i = 0; i < n; i++) {
    int u, k;
    std::cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      std::cin >> v;
      m[u - 1][v - 1] = true;
    }
  }

  bfs(m, d, v, s);

  for (int i = 0; i < n; i++) {
    std::cout << i + 1 << ' ' << d[i] << '\n';
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <stack>

constexpr int WHITE = 0;
constexpr int GRAY = 1;
constexpr int BLACK = 2;

std::vector<std::vector<int>> G(101);
std::vector<int> color(101, WHITE);
std::vector<int> d(101), f(101);
int t;

void dfs(int u) {
  std::stack<int> S;
  S.push(u);
  d[u] = ++t;
  color[u] = GRAY;

  while (!S.empty()) {
    int v = S.top();
    S.pop();

    for (auto& next : G[v]) {
      if (color[next] == WHITE) {
        d[next] = ++t;
        color[next] = GRAY;
        S.push(next);
      }
    }

    f[v] = ++t;
    color[v] = BLACK;
  }
}

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int u, e;
    std::cin >> u >> e;
    while (e--) {
      int v;
      std::cin >> v;
      G[u].push_back(v);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (color[i] == WHITE) {
      dfs(i);
    }
  }

  for (int i = 1; i <= n; ++i) {
    std::cout << i << " " << d[i] << " " << f[i] << "\n";
  }

  return 0;
}
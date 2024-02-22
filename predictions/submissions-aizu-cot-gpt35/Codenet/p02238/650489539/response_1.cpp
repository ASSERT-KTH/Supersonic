#include <iostream>
#include <vector>

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

void search_loop(int i, const std::vector<std::vector<int>>& G, std::vector<int>& color, std::vector<int>& d, std::vector<int>& f, int& t) {
  d[i] = ++t;
  color[i] = GRAY;
  for (int next = 1; next < G.size(); next++) {
    if (G[i][next] > 0 && color[next] == WHITE) {
      search_loop(next, G, color, d, f, t);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
}

void dfs(const std::vector<std::vector<int>>& G) {
  int n = G.size() - 1;
  std::vector<int> color(n + 1, WHITE);
  std::vector<int> d(n + 1);
  std::vector<int> f(n + 1);
  int t = 0;

  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i, G, color, d, f, t);
  }

  for (int i = 1; i <= n; i++) {
    std::cout << i << " " << d[i] << " " << f[i] << std::endl;
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> G(n + 1, std::vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    int vertex, e;
    std::cin >> vertex >> e;
    for (int j = 1; j <= e; j++) {
      int k;
      std::cin >> k;
      G[vertex][k] = 1;
    }
  }

  dfs(G);

  return 0;
}
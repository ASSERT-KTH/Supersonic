#include <functional>
#include <iostream>
#include <queue>
#include <vector>

#define INF (1 << 23)

int main() {
  int N, M, s, t, u, v;
  std::cin >> N >> M >> s >> t;
  s--;
  t--;
  std::vector<std::vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }
  
  // Rest of the code...
}
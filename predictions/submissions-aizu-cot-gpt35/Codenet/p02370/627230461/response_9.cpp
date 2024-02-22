#include <iostream>
#include <vector>
#include <queue>

int main() {
  int V, E;
  std::cin >> V >> E;

  std::vector<std::pair<int, int>> edge;
  std::vector<int> state(V, 0);

  edge.reserve(E);
  for (int i = 0; i < E; i++) {
    int s, t;
    std::cin >> s >> t;
    edge.emplace_back(s, t);
    state[t]++;
  }

  std::queue<int> ans;
  ans.reserve(V);
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push(i);
  }

  while (!ans.empty()) {
    int node = ans.front();
    ans.pop();

    for (const auto& e : edge) {
      if (e.first == node) {
        int t = e.second;
        state[t]--;
        if (state[t] == 0)
          ans.push(t);
      }
    }
  }

  while (!ans.empty()) {
    std::cout << ans.front() << std::endl;
    ans.pop();
  }

  return 0;
}
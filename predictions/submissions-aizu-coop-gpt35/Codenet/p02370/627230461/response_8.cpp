#include <iostream>
#include <vector>

int main() {
  int V, E;
  std::cin >> V >> E;

  std::vector<std::vector<int>> adjList(V);
  std::vector<int> state(V, 0);

  int maxVertex = 0;

  for (int i = 0; i < E; i++) {
    int s, t;
    std::cin >> s >> t;
    adjList[s].push_back(t);
    state[t]++;
    maxVertex = std::max(maxVertex, std::max(s, t));
  }

  std::vector<int> ans;
  ans.reserve(V); // Reserve memory for the maximum possible number of vertices

  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push_back(i);
  }

  for (int i = 0; i < ans.size(); i++) {
    int current = ans[i];
    for (int t : adjList[current]) {
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
  }

  for (int i = 0; i < V; i++) {
    std::cout << ans[i] << '\n';
  }

  return 0;
}
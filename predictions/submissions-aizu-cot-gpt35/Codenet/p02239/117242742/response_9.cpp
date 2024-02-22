#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
  std::vector<int> v(n, 0);
  std::vector<int> d(n, -1);

  for (int vertex = 0; vertex < n; vertex++)
    d[vertex] = -1;

  for (int vertex = 0; vertex < n; vertex++) {
    int source, num_neighbours;
    std::cin >> source >> num_neighbours;
    for (int j = 0; j < num_neighbours; j++) {
      int neighbour;
      std::cin >> neighbour;
      m[source - 1][neighbour - 1] = 1;
    }
  }

  v[0] = 1;
  d[0] = 0;
  std::queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int neighbour = 0; neighbour < n; neighbour++) {
      if (m[curr][neighbour] && !v[neighbour]) {
        d[neighbour] = d[curr] + 1;
        v[neighbour] = 1;
        q.push(neighbour);
      }
    }
  }

  for (int vertex = 0; vertex < n; vertex++)
    std::cout << vertex + 1 << ' ' << d[vertex] << '\n';

  return 0;
}
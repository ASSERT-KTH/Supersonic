#include <iostream>
#include <vector>
using namespace std;

size_t n;
vector<vector<size_t>> adjList;
vector<bool> visited;
vector<int> distances;

void bfs(size_t s) {
  visited[s] = true;
  distances[s] = 0;
  vector<size_t> q;
  q.push_back(s);
  size_t front = 0;
  while (front < q.size()) {
    size_t u = q[front++];
    for (size_t i = 0; i < adjList[u].size(); i++) {
      size_t v = adjList[u][i];
      if (!visited[v]) {
        distances[v] = distances[u] + 1;
        visited[v] = true;
        q.push_back(v);
      }
    }
  }
}

int main() {
  scanf("%zu", &n);
  adjList.resize(n);
  visited.resize(n, false);
  distances.resize(n, -1);
  for (size_t i = 0; i < n; i++) {
    size_t u, k;
    scanf("%zu %zu", &u, &k);
    u--;
    for (size_t j = 0; j < k; j++) {
      size_t v;
      scanf("%zu", &v);
      v--;
      adjList[u].push_back(v);
    }
  }
  bfs(0);
  for (size_t i = 0; i < n; i++)
    printf("%zu %d\n", i + 1, distances[i]);
  return 0;
}
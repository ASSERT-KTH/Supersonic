#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#define INF (1 << 23)

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int N, M, s, t;
  std::cin >> N >> M >> s >> t;
  s--;
  t--;
  std::vector<std::vector<int>> G(N);
  G.reserve(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    std::cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }
  std::vector<int> d1(N, INF);
  d1[s] = 0;
  std::vector<int> d2(N, INF);
  d2[t] = 0;
  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto neighbour : G[node]) {
      if (d1[neighbour] == INF) {
        d1[neighbour] = d1[node] + 1;
        que.push(neighbour);
      }
    }
  }
  que.push(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto neighbour : G[node]) {
      if (d2[neighbour] == INF) {
        d2[neighbour] = d2[node] + 1;
        que.push(neighbour);
      }
    }
  }
  int shortest = d1[t];
  std::vector<int> r1(shortest - 1, 0);
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
  }
  std::vector<int> r2(shortest - 1, 0);
  for (int i = 0; i < N; i++) {
    if (d2[i] < shortest - 1) {
      r2[d2[i]]++;
    }
  }
  long long ret = 0;
  for (int i = 0; i < shortest - 1; i++) {
    ret += 1LL * r1[i] * r2[shortest - i - 2];
  }
  std::cout << ret << "\n";
  return 0;
}
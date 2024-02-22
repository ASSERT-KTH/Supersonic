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

  std::vector<int> d1(N, INF);
  d1[s] = 0;
  std::vector<int> d2(N, INF);
  d2[t] = 0;

  std::queue<int> que;
  que.emplace(s);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int i = 0; i < G[node].size(); i++) {
      if (d1[G[node][i]] == INF) {
        d1[G[node][i]] = d1[node] + 1;
        que.emplace(G[node][i]);
      }
    }
  }

  que.emplace(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int i = 0; i < G[node].size(); i++) {
      if (d2[G[node][i]] == INF) {
        d2[G[node][i]] = d2[node] + 1;
        que.emplace(G[node][i]);
      }
    }
  }

  int shortest = d1[t];
  std::vector<int> r1;
  r1.reserve(shortest - 1);
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1.push_back(d1[i]);
    }
  }

  std::vector<int> r2;
  r2.reserve(shortest - 1);
  for (int i = 0; i < N; i++) {
    if (d2[i] < shortest - 1) {
      r2.push_back(d2[i]);
    }
  }

  long long ret = 0;
  for (int i = 0; i < shortest - 1; i++) {
    ret += 1LL * r1[i] * r2[shortest - i - 2];
  }

  std::cout << ret << std::endl;
  return 0;
}
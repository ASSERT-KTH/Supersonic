#include <iostream>
#include <queue>
#include <vector>

const int INF = 1 << 23;

int main() {
  int N, M, s, t, u, v;
  std::cin >> N >> M >> s >> t;
  s--;
  t--;
  std::vector<std::vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    G[u - 1].emplace_back(v - 1);
    G[v - 1].emplace_back(u - 1);
  }
  std::vector<int> d1(N, INF), d2(N, INF);
  d1[s] = d2[t] = 0;
  std::queue<int> que;
  que.push(s);
  que.push(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto &i : G[node]) {
      if (d1[i] == INF) {
        d1[i] = d1[node] + 1;
        que.push(i);
      }
      if (d2[i] == INF) {
        d2[i] = d2[node] + 1;
        que.push(i);
      }
    }
  }
  int shortest = d1[t];
  std::vector<int> r1(shortest - 1, 0), r2(shortest - 1, 0);
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
    if (d2[i] < shortest - 1) {
      r2[d2[i]]++;
    }
  }
  long long ret = 0;
  for (int i = 0; i < shortest - 1; i++) {
    ret += 1LL * r1[i] * r2[shortest - i - 2];
  }
  std::cout << ret << std::endl;
  return 0;
}
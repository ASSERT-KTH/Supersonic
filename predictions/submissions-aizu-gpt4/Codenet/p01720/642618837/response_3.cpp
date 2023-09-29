#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 23)

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, M, s, t, u, v;
  std::cin >> N >> M >> s >> t;
  s--; t--;

  std::vector<std::vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }
  
  std::vector<int> d1(N, INF), d2(N, INF);
  d1[s] = d2[t] = 0;

  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto next : G[node]) {
      if (d1[next] == INF) {
        d1[next] = d1[node] + 1;
        que.push(next);
      }
    }
  }
  
  que.push(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto next : G[node]) {
      if (d2[next] == INF) {
        d2[next] = d2[node] + 1;
        que.push(next);
      }
    }
  }
  
  int shortest = d1[t];
  std::vector<long long> r1(shortest, 0), r2(shortest, 0);
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest) r1[d1[i]]++;
    if (d2[i] < shortest) r2[d2[i]]++;
  }
  
  long long ret = 0;
  for (int i = 0; i < shortest - 1; i++) {
    ret += r1[i] * r2[shortest - i - 2];
  }
  std::cout << ret << '\n';
  return 0;
}
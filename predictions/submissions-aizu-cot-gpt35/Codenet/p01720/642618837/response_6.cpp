#include <cstdio>
#include <vector>
#include <queue>
#include <cstdint>

#define INF (1 << 23)

int main() {
  int N, M, s, t, u, v;
  scanf("%d", &N);
  scanf("%d", &M);
  scanf("%d", &s);
  s--;
  scanf("%d", &t);
  t--;

  std::vector<std::vector<int>> G(N);
  G.reserve(N); // Reserve memory for G

  for (int i = 0; i < M; i++) {
    scanf("%d", &u);
    scanf("%d", &v);
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  std::vector<int> d1(N, INF);
  std::vector<int> d2(N, INF);
  d1[s] = 0;
  d2[t] = 0;

  std::queue<int> que;
  que.push(s);
  que.push(t);

  while (!que.empty()) {
    int node = que.front();
    que.pop();

    for (auto neighbor : G[node]) {
      if (d1[neighbor] == INF) {
        d1[neighbor] = d1[node] + 1;
        que.push(neighbor);
      } else if (d2[neighbor] == INF) {
        d2[neighbor] = d2[node] + 1;
        que.push(neighbor);
      }
    }
  }

  int shortest = d1[t];
  std::vector<int> r1(shortest - 1, 0);
  std::vector<int> r2(shortest - 1, 0);

  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
    if (d2[i] < shortest - 1) {
      r2[d2[i]]++;
    }
  }

  int64_t ret = 0;
  for (int i = 0; i < shortest - 1; i++) {
    ret += static_cast<int64_t>(r1[i]) * r2[shortest - i - 2];
  }

  printf("%lld\n", ret);
  return 0;
}
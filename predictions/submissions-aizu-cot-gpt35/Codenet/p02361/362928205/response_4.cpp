#include <cstdio>
#include <array>
#include <queue>

const int MAX_V = 100000;
const int INF = 1000000000;

struct edge {
  int to, cost;
};

std::array<std::vector<edge>, MAX_V> G;
std::array<int, MAX_V> d;

struct compare {
  bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
    return lhs.first > rhs.first;
  }
};

int main() {
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);

  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].push_back({t, d});
  }

  d.fill(INF);
  d[r] = 0;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> q;
  q.emplace(0, r);

  while (!q.empty()) {
    const auto p = q.top();
    q.pop();

    const int nv = p.second;
    if (p.first > d[nv])
      continue;

    for (const auto& edge : G[nv]) {
      if (d[nv] + edge.cost < d[edge.to]) {
        d[edge.to] = d[nv] + edge.cost;
        q.emplace(d[edge.to], edge.to);
      }
    }
  }

  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", d[i]);
  }

  return 0;
}
#include <vector>
#include <limits>
#include <queue>
#include <iostream>

template <typename Weight> class Dinic {
public:
  Dinic(const int n) : n(n), g(n), INF(std::numeric_limits<Weight>::max()) {}
  void add_edge(const int src, const int dst, const Weight cap) {
    g[src].emplace_back(Edge(src, dst, cap, g[dst].size()));
    g[dst].emplace_back(Edge(dst, src, 0, g[src].size() - 1));
  }
  Weight MaximumFlow(const int s, const int t) {
    Weight flow = 0;
    for (std::vector<int> level(n, -1), iter(n); Bfs(s, level);) {
      iter.assign(n, 0);
      for (Weight f; (f = Dfs(level, iter, s, t, INF)) > 0;) {
        flow += f;
      }
    }
    return flow;
  }

private:
  struct Edge {
    int src, dst, rev;
    Weight weight;
    Edge(int f, int t, Weight cap, int rev = 0)
        : src(f), dst(t), rev(rev), weight(cap) {}
  };
  int n;
  std::vector<std::vector<Edge>> g;
  const Weight INF;
  bool Bfs(const int s, std::vector<int> &level) {
    std::queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto &e : g[v]) {
        if (e.weight > 0 && level[e.dst] == -1) {
          level[e.dst] = level[v] + 1;
          que.push(e.dst);
        }
      }
    }
    return level[n-1] != -1;
  }
  Weight Dfs(std::vector<int> &level, std::vector<int> &iter, int v, int t, Weight flow) {
    if (v == t)
      return flow;
    for (int &i = iter[v], N = g[v].size(); i < N; ++i) {
      Edge &e = g[v][i];
      if (e.weight > 0 && level[v] < level[e.dst]) {
        Weight d = Dfs(level, iter, e.dst, t, std::min(flow, e.weight));
        if (d > 0) {
          e.weight -= d;
          g[e.dst][e.rev].weight += d;
          return d;
        }
      }
    }
    return 0;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, u, v, c;
  std::cin >> n >> m;
  Dinic<int> flow(n);
  for (int i = 0; i < m; ++i) {
    std::cin >> u >> v >> c;
    flow.add_edge(u, v, c);
  }
  std::cout << flow.MaximumFlow(0, n - 1) << '\n';
  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

class Dinic {
public:
  Dinic(const int n) : n(n), g(n), INF(std::numeric_limits<int>::max()) {}
  void add_edge(const int& src, const int& dst, const int& cap) {
    g[src].emplace_back(Edge(src, dst, cap, g[dst].size()));
    g[dst].emplace_back(Edge(dst, src, 0, g[src].size() - 1));
  }
  int MaximumFlow(const int s, const int t) {
    int flow = 0;
    while (true) {
      std::vector<int> level(n, -1), iter(n);
      Bfs(s, level);
      if (level[t] == -1)
        break;
      for (int f = 0; (f = Dfs(level, iter, s, t, INF)) > 0;)
        flow += f;
    }
    return flow;
  }

private:
  struct Edge {
    int src, dst, rev;
    int weight;
    Edge(const int& f, const int& t, const int& cap, const int& rev = 0)
        : src(f), dst(t), rev(rev), weight(cap) {}
  };
  int n;
  std::vector<std::vector<Edge>> g;
  const int INF;
  void Bfs(const int s, std::vector<int>& level) {
    std::deque<int> que;
    for (level[s] = 0, que.push_back(s); !que.empty();) {
      const int v = que.front();
      que.pop_front();
      for (auto& e : g[v]) {
        if (e.weight > 0 && level[e.dst] == -1) {
          level[e.dst] = level[v] + 1;
          que.push_back(e.dst);
        }
      }
    }
  }
  int Dfs(std::vector<int>& level, std::vector<int> iter, int v, const int t, int flow) {
    if (v == t)
      return flow;
    for (int& i = iter[v], N = g[v].size(); i < N; ++i) {
      Edge& e = g[v][i];
      if (e.weight > 0 && level[v] < level[e.dst]) {
        int d = Dfs(level, iter, e.dst, t, std::min(flow, e.weight));
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
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n, m, u, v, c;
  std::cin >> n >> m;
  Dinic flow(n);
  for (int i = 0; i < m; ++i) {
    std::cin >> u >> v >> c;
    flow.add_edge(u, v, c);
  }
  std::cout << flow.MaximumFlow(0, n - 1) << std::endl;
  return 0;
}
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
template <typename Weight> class Dinic {
public:
  Dinic(const int n) : n(n), g(n), INF(numeric_limits<Weight>::max()) {}
  void add_edge(const int src, const int dst, const Weight cap) {
    g[src].emplace_back(Edge(src, dst, cap, g[dst].size()));
    g[dst].emplace_back(Edge(dst, src, 0, g[src].size() - 1));
  }
  Weight MaximumFlow(const int s, const int t) {
    Weight flow = 0;
    while (true) {
      vector<int> level(n, -1), iter(n);
      Bfs(s, level);
      if (level[t] == -1)
        break;
      for (Weight f = 0; (f = Dfs(level, iter, s, t, INF)) > 0;)
        flow += f;
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
  vector<vector<Edge>> g;
  const Weight INF;
  void Bfs(const int s, vector<int> &level) {
    queue<int> que;
    for (level[s] = 0, que.push(s); !que.empty();) {
      const int v = que.front();
      que.pop();
      for (auto &e : g[v]) {
        if (e.weight > 0 && level[e.dst] == -1) {
          level[e.dst] = level[v] + 1;
          que.push(e.dst);
        }
      }
    }
  }
  Weight Dfs(vector<int> &level, vector<int> &iter, int v, int t, Weight flow) {
    if (v == t)
      return flow;
    for (int &i = iter[v], N = g[v].size(); i < N; ++i) {
      Edge &e = g[v][i];
      if (e.weight > 0 && level[v] < level[e.dst]) {
        Weight d = Dfs(level, iter, e.dst, t, min(flow, e.weight));
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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, u, v, c;
  cin >> n >> m;
  Dinic<int> flow(n);
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    flow.add_edge(u, v, c);
  }
  cout << flow.MaximumFlow(0, n - 1) << endl;
  return 0;
}

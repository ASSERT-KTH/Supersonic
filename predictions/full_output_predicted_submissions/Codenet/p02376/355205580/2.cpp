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
      BFS(s, level);
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
        if (e.weight > 0 && level[e
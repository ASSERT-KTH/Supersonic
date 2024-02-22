#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Dinic {
public:
  Dinic(int n) : n(n), g(n), INF(numeric_limits<int>::max()) {}
  
  void add_edge(int src, int dst, int cap) {
    g[src].emplace_back(Edge(src, dst, cap, g[dst].size()));
    g[dst].emplace_back(Edge(dst, src, 0, g[src].size() - 1));
  }
  
  int MaximumFlow(int s, int t) {
    int flow = 0;
    while (true) {
      vector<int> level(n, -1), iter(n);
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
    int src, dst, rev, weight;
    Edge(int f, int t, int cap, int rev = 0) : src(f), dst(t), rev(rev), weight(cap) {}
  };
  
  int n;
  vector<vector<Edge>> g;
  const int INF;
  
  void Bfs(int s, vector<int> &level) {
    queue<int> que({s});
    level[s] = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (Edge &e : g[v]) {
        if (e.weight > 0 && level[e.dst] == -1) {
          level[e.dst] = level[v] + 1;
          que.push(e.dst);
        }
      }
    }
  }
  
  int Dfs(vector<int> &level, vector<int> &iter, int v, int t, int flow) {
    if (v == t)
      return flow;
    for (Edge &e : g[v]) {
      if (e.weight > 0 && level[v] < level[e.dst]) {
        int d = Dfs(level, iter, e.dst, t, min(flow, e.weight));
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
  int n, m, u, v, c;
  cin >> n >> m;
  Dinic flow(n);
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    flow.add_edge(u, v, c);
  }
  cout << flow.MaximumFlow(0, n - 1) << endl;
  return 0;
}
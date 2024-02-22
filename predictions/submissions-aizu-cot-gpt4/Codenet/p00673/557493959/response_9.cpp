#include <cstdio>
#include <unordered_map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int V_MAX = 6000;
const int CAPA_INF = 1 << 29;
const int COST_INF = 1 << 29;

template <class T, class U>
struct edge {
  int v, rev;
  T capa;
  U cost;
  T flow;
};

template <class T, class U>
void add_directed_edge(vector<edge<T, U>> *G, int u, int v, T capa, U cost) {
  G[u].emplace_back((edge<T, U>){v, G[v].size(), capa, cost, 0});
  G[v].emplace_back((edge<T, U>){u, G[u].size() - 1, 0, -cost, 0});
}

template <class T, class U>
pair<T, U> augment(int n, vector<edge<T, U>> *G, int s, int t, U *pot) {
  static int pre[V_MAX];
  static U d[V_MAX];
  rep(u, n) d[u] = (u == s ? 0 : COST_INF);
  bool ok = false;
  priority_queue<pair<U, int>> Q;
  Q.emplace(0, s);
  while (!Q.empty()) {
    int u = Q.top().second;
    U cost = -Q.top().first;
    Q.pop();
    if (cost < d[u])
      continue;
    if (u == t)
      ok = true;
    rep(i, G[u].size()) {
      edge<T, U> &e = G[u][i];
      if (e.capa - e.flow > 0) {
        U cost2 = cost + e.cost + pot[u] - pot[e.v];
        if (cost2 < d[e.v]) {
          d[e.v] = cost2;
          pre[e.v] = e.rev;
          Q.emplace(-cost2, e.v);
        }
      }
    }
  }
  // ... (the rest of the program remains unchanged)
}
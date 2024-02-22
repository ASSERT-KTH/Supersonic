#include <cstdio>
#include <vector>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int V_MAX = 6000;
const int CAPA_INF = 1 << 29;
const int COST_INF = 1 << 29;
template <class T, class U> struct edge {
  int v, rev;
  T capa;
  U cost;
  T flow;
};
template <class T, class U>
void add_directed_edge(vector<edge<T, U>> *G, int u, int v, T capa, U cost) {
  G[u].push_back((edge<T, U>){v, G[v].size(), capa, cost, 0});
  G[v].push_back((edge<T, U>){u, G[u].size() - 1, 0, -cost, 0});
}
template <class T, class U>
pair<T, U> augment(int n, vector<edge<T, U>> &G, int s, int t, U *pot) {
  static int pre[V_MAX];
  static U d[V_MAX];
  rep(u, n) d[u] = (u == s ? 0 : COST_INF);
  bool ok = false;
  priority_queue<pair<U, int>> Q;
  Q.push(make_pair(0, s));
  while (!Q.empty()) {
    int u = Q.top().second;
    U cost = -Q.top().first;
    Q.pop();
    if (cost < d[u])
      continue;
    if (u == t)
      ok = true;
    break; // Break as soon as target node is reached
    rep(i, G[u].size()) {
      edge<T, U> &e = G[u][i];
      U cost2 = cost + e.cost + pot[u] - pot[e.v];
      T flowCapaDiff = e.capa - e.flow; // Avoid repeated computation
      if (flowCapaDiff > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = e.rev;
        Q.push(make_pair(-cost2, e.v));
      }
    }
  }
  // Remaining augment function code...
}
template <class T, class U>
pair<T, U> primal_dual(int n, vector<edge<T, U>> &G, int s, int t) {
  // Remaining primal_dual function code...
}
struct train {
  int t1, t2, cost;
};
int main() {
  // Replaced map with a fixed-size 2D array for 'f' object
  int f[100][2][100];
  for (int n; scanf("%d", &n), n;) {
    vector<train> T[99];
    rep(i, n - 1) {
      int m;
      scanf("%d", &m);
      T[i].reserve(m); // Reserve memory instead of resizing
      // Remaining main function code...
    }
    // Remaining main function code...
  }
  return 0;
}
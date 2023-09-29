#include <cstdio>
#include <map>
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
pair<T, U> augment(int n, vector<edge<T, U>> *G, int s, int t, U *pot) {
  static int pre[V_MAX];
  static U d[V_MAX];
  rep(u, n) d[u] = (u == s ? 0 : COST_INF);
  bool ok = false;
  priority_queue<pair<U, int>, vector<pair<U, int>>, greater<pair<U, int>>> Q;
  Q.push(make_pair(0, s));
  while (!Q.empty()) {
    int u = Q.top().second;
    U cost = Q.top().first;
    Q.pop();
    if (cost > d[u])
      continue;
    if (u == t)
      ok = true;
    rep(i, G[u].size()) {
      edge<T, U> &e = G[u][i];
      U cost2 = cost + e.cost + pot[u] - pot[e.v];
      if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = e.rev;
        Q.push(make_pair(cost2, e.v));
      }
    }
  }
  if (!ok)
    return make_pair(0, 0);
  T water = CAPA_INF;
  for (int v = t; v != s;) {
    edge<T, U> &e1 = G[v][pre[v]];
    edge<T, U> &e2 = G[e1.v][e1.rev];
    water = min(water, e2.capa - e2.flow);
    v = e1.v;
  }
  U cost = 0;
  for (int v = t; v != s;) {
    edge<T, U> &e1 = G[v][pre[v]];
    edge<T, U> &e2 = G[e1.v][e1.rev];
    e1.flow -= water;
    e2.flow += water;
    cost += water * e2.cost;
    v = e1.v;
  }
  rep(u, n) pot[u] += d[u];
  return make_pair(water, cost);
}
template <class T, class U>
pair<T, U> primal_dual(int n, vector<edge<T, U>> *G, int s, int t) {
  T ans1 = 0;
  U ans2 = 0;
  static U pot[V_MAX];
  while (1) {
    pair<T, U> tmp = augment(n, G, s, t, pot);
    if (tmp.first == 0)
      break;
    ans1 += tmp.first;
    ans2 += tmp.second;
  }
  return make_pair(ans1, ans2);
}
struct train {
  int t1, t2, cost;
};
int main() {
  for (int n; scanf("%d", &n), n;) {
    vector<train> T[99];
    rep(i, n - 1) {
      int m;
      scanf("%d", &m);
      T[i].resize(m);
      rep(j, m) scanf("%d%d%d", &T[i][j].t1, &T[i][j].t2, &T[i][j].cost);
    }
    int n_class;
    scanf("%d", &n_class);
    int V = 0;
    map<int, int> f[100][2];
    map<int, int>::iterator it, jt;
    rep(i, n - 1) rep(j, T[i].size()) {
      int t1 = T[i][j].t1, t2 = T[i][j].t2;
      if (f[i][0].count(t1) == 0)
        f[i][0][t1] = V++;
      if (f[i + 1][0].count(t2) == 0)
        f[i + 1][0][t2] = V++;
      if (f[i + 1][1].count(t2) == 0)
        f[i + 1][1][t2] = V++;
    }
    int s = V++;
    int t = V++;
    static vector<edge<int, int>> G[V_MAX];
    rep(u, V) G[u].clear();
    add_directed_edge(G, s, f[0][0].begin()->second, n_class, 0);
    add_directed_edge(G, f[n - 1][0].rbegin()->second, t, n_class, 0);
    rep(i, n) {
      for (it = f[i][0].begin(); it != f[i][0].end(); ++it) {
        jt = it;
        ++jt;
        if (jt != f[i][0].end()) {
          add_directed_edge(G, it->second, jt->second, n_class, 0);
        }
      }
      for (it = f[i][1].begin(); it != f[i][1].end(); ++it) {
        int t = it->first;
        add_directed_edge(G, it->second, f[i][0][t], 1, 0);
      }
    }
    rep(i, n - 1) rep(j, T[i].size()) {
      add_directed_edge(G, f[i][0][T[i][j].t1], f[i + 1][1][T[i][j].t2], 1,
                        T[i][j].cost);
    }
    pair<int, int> ans = primal_dual(V, G, s, t);
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}

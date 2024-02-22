#include <vector>
#include <queue>
#include <map>

#define rep(i, n) for (int i = 0; i < (n); i++)

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
void add_directed_edge(std::vector<edge<T, U>>& G, int u, int v, T capa, U cost) {
  G[u].push_back((edge<T, U>){v, G[v].size(), capa, cost, 0});
  G[v].push_back((edge<T, U>){u, G[u].size() - 1, 0, -cost, 0});
}

template <class T, class U>
std::pair<T, U> augment(int n, std::vector<edge<T, U>>& G, int s, int t, U* pot) {
  int pre[V_MAX];
  U d[V_MAX];
  rep(u, n) d[u] = (u == s ? 0 : COST_INF);
  bool ok = false;
  std::priority_queue<std::pair<U, int>> Q;
  Q.push(std::make_pair(0, s));
  while (!Q.empty()) {
    int u = Q.top().second;
    U cost = -Q.top().first;
    Q.pop();
    if (cost < d[u])
      continue;
    if (u == t)
      ok = true;
    rep(i, G[u].size()) {
      edge<T, U>& e = G[u][i];
      U cost2 = cost + e.cost + pot[u] - pot[e.v];
      if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = e.rev;
        Q.push(std::make_pair(-cost2, e.v));
      }
    }
  }
  if (!ok)
    return std::make_pair(0, 0);
  T water = CAPA_INF;
  for (int v = t; v != s;) {
    edge<T, U>& e1 = G[v][pre[v]];
    edge<T, U>& e2 = G[e1.v][e1.rev];
    water = std::min(water, e2.capa - e2.flow);
    v = e1.v;
  }
  U cost = 0;
  for (int v = t; v != s;) {
    edge<T, U>& e1 = G[v][pre[v]];
    edge<T, U>& e2 = G[e1.v][e1.rev];
    e1.flow -= water;
    e2.flow += water;
    cost += water * e2.cost;
    v = e1.v;
  }
  rep(u, n) pot[u] += d[u];
  return std::make_pair(water, cost);
}

template <class T, class U>
std::pair<T, U> primal_dual(int n, std::vector<edge<T, U>>& G, int s, int t) {
  T ans1 = 0;
  U ans2 = 0;
  U pot[V_MAX];
  while (1) {
    std::pair<T, U> tmp = augment(n, G, s, t, pot);
    if (tmp.first == 0)
      break;
    ans1 += tmp.first;
    ans2 += tmp.second;
  }
  return std::make_pair(ans1, ans2);
}

struct train {
  int t1, t2, cost;
};

int main() {
  std::vector<std::vector<train>> T;
  for (int n; std::scanf("%d", &n), n;) {
    T.resize(n - 1);
    rep(i, n - 1) {
      int m;
      std::scanf("%d", &m);
      T[i].resize(m);
      rep(j, m) std::scanf("%d%d%d", &T[i][j].t1, &T[i][j].t2, &T[i][j].cost);
    }
    int n_class;
    std::scanf("%d", &n_class);
    int V = 0;
    std::map<int, int> f[2];
    std::map<int, int>::iterator it, jt;
    rep(i, n - 1) rep(j, T[i].size()) {
      int t1 = T[i][j].t1, t2 = T[i][j].t2;
      if (f[0].count(t1) == 0)
        f[0][t1] = V++;
      if (f[1].count(t2) == 0)
        f[1][t2] = V++;
      if (f[1].count(t2) == 0)
        f[1][t2] = V++;
    }
    int s = V++;
    int t = V++;
    std::vector<edge<int, int>> G[V_MAX];
    add_directed_edge(G, s, f[0].begin()->second, n_class, 0);
    add_directed_edge(G, f[n - 2][0].rbegin()->second, t, n_class, 0);
    rep(i, n - 1) {
      for (it = f[0].begin(); it != f[0].end(); ++it) {
        jt = it;
        ++jt;
        if (jt != f[0].end()) {
          add_directed_edge(G, it->second, jt->second, n_class, 0);
        }
      }
      for (it = f[1].begin(); it != f[1].end(); ++it) {
        int t = it->first;
        add_directed_edge(G, it->second, f[0][t], 1, 0);
      }
    }
    rep(i, n - 1) rep(j, T[i].size()) {
      add_directed_edge(G, f[0][T[i][j].t1], f[1][T[i][j].t2], 1, T[i][j].cost);
    }
    std::pair<int, int> ans = primal_dual(V, G, s, t);
    std::printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}
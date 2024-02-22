#include <vector>
#include <map>
#include <queue>

constexpr int V_MAX = 6000;
constexpr int CAPA_INF = 1 << 29;
constexpr int COST_INF = 1 << 29;

template <class T, class U>
struct edge {
  int v, rev;
  T capa;
  U cost;
  T flow;
};

template <class T, class U>
void add_directed_edge(std::vector<std::vector<edge<T, U>>>& G, int u, int v, T capa, U cost) {
  G[u].emplace_back(edge<T, U>{v, static_cast<int>(G[v].size()), capa, cost, 0});
  G[v].emplace_back(edge<T, U>{u, static_cast<int>(G[u].size()) - 1, 0, -cost, 0});
}

template <class T, class U>
std::pair<T, U> augment(int n, std::vector<std::vector<edge<T, U>>>& G, int s, int t, U* pot) {
  static int pre[V_MAX];
  static U d[V_MAX];
  for (int u = 0; u < n; u++) {
    d[u] = (u == s ? 0 : COST_INF);
  }
  bool ok = false;
  std::priority_queue<std::pair<U, int>> Q;
  Q.emplace(0, s);
  while (!Q.empty()) {
    int u = Q.top().second;
    U cost = -Q.top().first;
    Q.pop();
    if (cost < d[u])
      continue;
    if (u == t)
      ok = true;
    for (auto& e : G[u]) {
      U cost2 = cost + e.cost + pot[u] - pot[e.v];
      if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = e.rev;
        Q.emplace(-cost2, e.v);
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
  for (int u = 0; u < n; u++) {
    pot[u] += d[u];
  }
  return std::make_pair(water, cost);
}

template <class T, class U>
std::pair<T, U> primal_dual(int n, std::vector<std::vector<edge<T, U>>>& G, int s, int t) {
  T ans1 = 0;
  U ans2 = 0;
  U pot[V_MAX]{};
  while (true) {
    auto tmp = augment(n, G, s, t, pot);
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
  for (int n; std::scanf("%d", &n), n;) {
    std::vector<std::vector<train>> T(n - 1);
    for (int i = 0; i < n - 1; i++) {
      int m;
      std::scanf("%d", &m);
      T[i].resize(m);
      for (int j = 0; j < m; j++) {
        std::scanf("%d%d%d", &T[i][j].t1, &T[i][j].t2, &T[i][j].cost);
      }
    }
    int n_class;
    std::scanf("%d", &n_class);
    int V = 0;
    std::map<int, int> f[100][2];
    for (int i = 0; i < n - 1; i++) {
      for (const auto& train : T[i]) {
        int t1 = train.t1, t2 = train.t2;
        if (f[i][0].count(t1) == 0)
          f[i][0][t1] = V++;
        if (f[i + 1][0].count(t2) == 0)
          f[i + 1][0][t2] = V++;
        if (f[i + 1][1].count(t2) == 0)
          f[i + 1][1][t2] = V++;
      }
    }
    int s = V++;
    int t = V++;
    std::vector<std::vector<edge<int, int>>> G(V_MAX);
    for (auto& vec : G) {
      vec.reserve(4 * n);
    }
    add_directed_edge(G, s, f[0][0].begin()->second, n_class, 0);
    add_directed_edge(G, f[n - 1][0].rbegin()->second, t, n_class, 0);
    for (int i = 0; i < n; i++) {
      for (auto it = f[i][0].begin(); it != f[i][0].end(); ++it) {
        auto jt = it;
        ++jt;
        if (jt != f[i][0].end()) {
          add_directed_edge(G, it->second, jt->second, n_class, 0);
        }
      }
      for (auto it = f[i][1].begin(); it != f[i][1].end(); ++it) {
        int t = it->first;
        add_directed_edge(G, it->second, f[i][0][t], 1, 0);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      for (const auto& train : T[i]) {
        add_directed_edge(G, f[i][0][train.t1], f[i + 1][1][train.t2], 1, train.cost);
      }
    }
    auto ans = primal_dual(V, G, s, t);
    std::printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}
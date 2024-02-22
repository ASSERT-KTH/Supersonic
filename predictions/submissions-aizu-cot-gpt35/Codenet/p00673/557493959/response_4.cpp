#include <cstdio>
#include <vector>
#include <map>
#include <queue>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const int V_MAX = 6000;
const int CAPA_INF = 1 << 29;

template <class T>
struct edge {
  int v, rev;
  T capa, flow;
};

template <class T>
void add_directed_edge(vector<edge<T>>& G, int u, int v, T capa) {
  G[u].emplace_back(edge<T>{v, G[v].size(), capa, 0});
  G[v].emplace_back(edge<T>{u, G[u].size() - 1, 0, 0});
}

template <class T>
pair<T, T> augment(int n, vector<edge<T>>& G, int s, int t, vector<T>& pot) {
  static vector<int> pre(V_MAX);
  static vector<T> d(V_MAX);
  rep(u, n) d[u] = (u == s ? 0 : V_MAX);
  bool ok = false;
  priority_queue<pair<T, int>> Q;
  Q.emplace(0, s);
  while (!Q.empty()) {
    int u = Q.top().second;
    T cost = -Q.top().first;
    Q.pop();
    if (cost < d[u])
      continue;
    if (u == t)
      ok = true;
    for (const auto& e : G[u]) {
      T cost2 = cost + pot[u] - pot[e.v];
      if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = e.rev;
        Q.emplace(-cost2, e.v);
      }
    }
  }
  if (!ok)
    return make_pair(0, 0);
  T water = CAPA_INF;
  for (int v = t; v != s;) {
    edge<T>& e1 = G[v][pre[v]];
    edge<T>& e2 = G[e1.v][e1.rev];
    water = min(water, e2.capa - e2.flow);
    v = e1.v;
  }
  T cost = 0;
  for (int v = t; v != s;) {
    edge<T>& e1 = G[v][pre[v]];
    edge<T>& e2 = G[e1.v][e1.rev];
    e1.flow -= water;
    e2.flow += water;
    cost += water * e2.cost;
    v = e1.v;
  }
  rep(u, n) pot[u] += d[u];
  return make_pair(water, cost);
}

template <class T>
pair<T, T> primal_dual(int n, vector<edge<T>>& G, int s, int t) {
  T ans1 = 0;
  T ans2 = 0;
  vector<T> pot(V_MAX);
  while (1) {
    pair<T, T> tmp = augment(n, G, s, t, pot);
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
    vector<map<int, int>> f[100][2];
    rep(i, n - 1) rep(j, T[i].size()) {
      int t1 = T[i][j].t1, t2 = T[i][j].t2;
      if (f[i][0].count(t1) == 0)
        f[i][0].emplace(t1, V++);
      if (f[i + 1][0].count(t2) == 0)
        f[i + 1][0].emplace(t2, V++);
      if (f[i + 1][1].count(t2) == 0)
        f[i + 1][1].emplace(t2, V++);
    }
    int s = V++;
    int t = V++;
    vector<vector<edge<int>>> G(V);
    rep(u, V) G[u].reserve(10);
    add_directed_edge(G, s, f[0][0].begin()->second, n_class);
    add_directed_edge(G, f[n - 1][0].rbegin()->second, t, n_class);
    rep(i, n) {
      for (auto it = f[i][0].begin(); it != f[i][0].end(); ++it) {
        auto jt = it;
        ++jt;
        if (jt != f[i][0].end()) {
          add_directed_edge(G, it->second, jt->second, n_class);
        }
      }
      for (auto it = f[i][1].begin(); it != f[i][1].end(); ++it) {
        int t = it->first;
        add_directed_edge(G, it->second, f[i][0][t], 1);
      }
    }
    rep(i, n - 1) rep(j, T[i].size()) {
      add_directed_edge(G, f[i][0][T[i][j].t1], f[i + 1][1][T[i][j].t2], 1);
    }
    pair<int, int> ans = primal_dual(V, G, s, t);
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <queue>

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
void add_directed_edge(vector<edge<T, U>>& G, int u, int v, T capa, U cost) {
  G[u].push_back((edge<T, U>){v, G[v].size(), capa, cost, 0});
  G[v].push_back((edge<T, U>){u, G[u].size() - 1, 0, -cost, 0});
}

template <class T, class U>
pair<T, U> augment(int n, vector<edge<T, U>>& G, int s, int t, U* pot) {
  static int pre[V_MAX];
  static U d[V_MAX];
  for (int u = 0; u < n; u++) {
    d[u] = (u == s ? 0 : COST_INF);
  }
  bool ok = false;
  priority_queue<pair<U, int>> Q;
  Q.push(make_pair(0, s));
  while (!Q.empty()) {
    int u = Q.top().second;
    U cost = -Q.top().first;
    Q.pop();
    if (cost < d[u]) {
      continue;
    }
    if (u == t) {
      ok = true;
    }
    for (edge<T, U>& e : G[u]) {
      U cost2 = cost + e.cost + pot[u] - pot[e.v];
      if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = e.rev;
        Q.push(make_pair(-cost2, e.v));
      }
    }
  }
  if (!ok) {
    return make_pair(0, 0);
  }
  T water = CAPA_INF;
  for (int v = t; v != s;) {
    edge<T, U>& e1 = G[v][pre[v]];
    edge<T, U>& e2 = G[e1.v][e1.rev];
    water = min(water, e2.capa - e2.flow);
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
  return make_pair(water, cost);
}

template <class T, class U>
pair<T, U> primal_dual(int n, vector<edge<T, U>>& G, int s, int t) {
  T ans1 = 0;
  U ans2 = 0;
  static U pot[V_MAX];
  while (1) {
    pair<T, U> tmp = augment(n, G, s, t, pot);
    if (tmp.first == 0) {
      break;
    }
    ans1 += tmp.first;
    ans2 += tmp.second;
  }
  return make_pair(ans1, ans2);
}

struct train {
  int t1, t2, cost;
};

int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    vector<train> T[99];

    for (int i = 0; i < n - 1; i++) {
      int m;
      scanf("%d", &m);
      T[i].reserve(m);
      for (int j = 0; j < m; j++) {
        scanf("%d%d%d", &T[i][j].t1, &T[i][j].t2, &T[i][j].cost);
      }
    }

    int n_class;
    scanf("%d", &n_class);

    int V = 0;
    unordered_map<int, int> f[100][2];
    rep(i, n - 1) {
      for (const train& t : T[i]) {
        int t1 = t.t1, t2 = t.t2;
        f[i][0].emplace(t1, V++);
        f[i + 1][0].emplace(t2, V++);
        f[i + 1][1].emplace(t2, V++);
      }
    }

    int s = V++;
    int t = V++;
    vector<edge<int, int>> G[V_MAX];
    for (int u = 0; u < V; u++) {
      G[u].clear();
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
      for (const train& t : T[i]) {
        add_directed_edge(G, f[i][0][t.t1], f[i + 1][1][t.t2], 1, t.cost);
      }
    }

    pair<int, int> ans = primal_dual(V, G, s, t);
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}
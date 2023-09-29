#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int V_MAX = 6000;
const int CAPA_INF = 1 << 29;
const int COST_INF = 1 << 29;
struct edge {
  int v, rev;
  int capa;
  int cost;
  int flow;
};

void add_directed_edge(vector<edge> *G, int u, int v, int capa, int cost) {
  G[u].push_back({v, (int)G[v].size(), capa, cost, 0});
  G[v].push_back({u, (int)G[u].size() - 1, 0, -cost, 0});
}

pair<int, int> augment(int n, vector<edge> *G, int s, int t, int *pot) {
  static int pre[V_MAX], d[V_MAX];
  fill(d, d + n, COST_INF); d[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  Q.push({0, s});
  while (!Q.empty()) {
    int u = Q.top().second;
    int cost = Q.top().first;
    Q.pop();
    if (cost > d[u]) continue;
    for (edge &e : G[u]) {
      int cost2 = cost + e.cost + pot[u] - pot[e.v];
      if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = u;
        Q.push({cost2, e.v});
      }
    }
  }
  if (d[t] == COST_INF) return {0, 0};
  int water = CAPA_INF;
  for (int v = t; v != s; v = G[pre[v]][G[v][pre[v]].rev].v)
    water = min(water, G[pre[v]][G[v][pre[v]].rev].capa - G[pre[v]][G[v][pre[v]].rev].flow);
  int cost = 0;
  for (int v = t; v != s; v = G[pre[v]][G[v][pre[v]].rev].v) {
    edge &e1 = G[pre[v]][G[v][pre[v]].rev], &e2 = G[v][pre[v]];
    e1.flow += water;
    e2.flow -= water;
    cost += water * e1.cost;
  }
  for (int i = 0; i < n; i++) pot[i] += d[i];
  return {water, cost};
}

pair<int, int> primal_dual(int n, vector<edge> *G, int s, int t) {
  int ans1 = 0, ans2 = 0, pot[V_MAX] = {};
  for (pair<int, int> tmp; (tmp = augment(n, G, s, t, pot)).first > 0; )
    ans1 += tmp.first, ans2 += tmp.second;
  return {ans1, ans2};
}

struct train {
  int t1, t2, cost;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int n; cin >> n && n;) {
    vector<train> T[99];
    rep(i, n - 1) {
      int m;
      cin >> m;
      T[i].resize(m);
      for (auto &t : T[i]) cin >> t.t1 >> t.t2 >> t.cost;
    }
    int n_class;
    cin >> n_class;
    int V = 0;
    map<int, int> f[100][2];
    rep(i, n - 1) for (auto &t : T[i]) {
      if (!f[i][0].count(t.t1)) f[i][0][t.t1] = V++;
      if (!f[i + 1][0].count(t.t2)) f[i + 1][0][t.t2] = V++, f[i + 1][1][t.t2] = V++;
    }
    int s = V++, t = V++;
    vector<edge> G[V_MAX];
    add_directed_edge(G, s, f[0][0].begin()->second, n_class, 0);
    add_directed_edge(G, f[n - 1][0].rbegin()->second, t, n_class, 0);
    rep(i, n) for (auto &p : f[i][0]) {
      auto it = next(f[i][0].find(p.first));
      if (it != f[i][0].end()) add_directed_edge(G, p.second, it->second, n_class, 0);
    }
    rep(i, n) for (auto &p : f[i][1]) add_directed_edge(G, p.second, f[i][0][p.first], 1, 0);
    rep(i, n - 1) for (auto &t : T[i]) add_directed_edge(G, f[i][0][t.t1], f[i + 1][1][t.t2], 1, t.cost);
    pair<int, int> ans = primal_dual(V, G, s, t);
    cout << ans.first << ' ' << ans.second << '\n';
  }
  return 0;
}
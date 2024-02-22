#include <cstdio>
#include <vector>
#include <algorithm>

struct edge {
  int v, rev;
  int capa;
  int cost;
  int flow;
};

template <class T, class U>
void add_directed_edge(std::vector<edge>& G, int u, int v, T capa, U cost) {
  G[u].push_back({v, G[v].size(), capa, cost, 0});
  G[v].push_back({u, G[u].size() - 1, 0, -cost, 0});
}

template <class T, class U>
std::pair<T, U> augment(int n, std::vector<edge>& G, int s, int t, U* pot) {
  static std::vector<int> pre;
  static std::vector<U> d;
  pre.resize(n);
  d.resize(n);

  for (int u = 0; u < n; u++) {
    d[u] = (u == s ? 0 : std::numeric_limits<U>::max());
  }

  bool ok = false;
  std::priority_queue<std::pair<U, int>> Q;
  Q.push(std::make_pair(0, s));

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

    for (edge& e : G[u]) {
      U cost2 = cost + e.cost + pot[u] - pot[e.v];

      if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = e.rev;
        Q.push(std::make_pair(-cost2, e.v));
      }
    }
  }

  if (!ok) {
    return std::make_pair(0, 0);
  }

  T water = std::numeric_limits<T>::max();
  int v = t;

  while (v != s) {
    edge& e1 = G[v][pre[v]];
    edge& e2 = G[e1.v][e1.rev];
    water = std::min(water, e2.capa - e2.flow);
    v = e1.v;
  }

  U cost = 0;
  v = t;

  while (v != s) {
    edge& e1 = G[v][pre[v]];
    edge& e2 = G[e1.v][e1.rev];
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
std::pair<T, U> primal_dual(int n, std::vector<edge>& G, int s, int t) {
  T ans1 = 0;
  U ans2 = 0;
  std::vector<U> pot(n);

  while (true) {
    std::pair<T, U> tmp = augment(n, G, s, t, pot.data());

    if (tmp.first == 0) {
      break;
    }

    ans1 += tmp.first;
    ans2 += tmp.second;
  }

  return std::make_pair(ans1, ans2);
}

struct train {
  int t1, t2, cost;
};

int main() {
  int n;

  while (std::scanf("%d", &n), n) {
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
    std::vector<std::vector<std::pair<int, int>>> f(n, std::vector<std::pair<int, int>>(2));
    int last_train_id = 0;

    for (int i = 0; i < n - 1; i++) {
      for (const train& t : T[i]) {
        int t1 = t.t1, t2 = t.t2;

        if (f[i][0].size() == 0 || f[i][0].back().first != t1) {
          f[i][0].push_back({t1, V++});
        }

        if (f[i + 1][0].size() == 0 || f[i + 1][0].back().first != t2) {
          f[i + 1][0].push_back({t2, V++});
        }

        if (f[i + 1][1].size() == 0 || f[i + 1][1].back().first != t2) {
          f[i + 1][1].push_back({t2, V++});
        }

        last_train_id = f[i + 1][0].back().second;
      }
    }

    int s = V++;
    int t = V++;
    std::vector<edge> G(V);

    for (int u = 0; u < V; u++) {
      G[u].clear();
    }

    add_directed_edge(G, s, f[0][0][0].second, n_class, 0);
    add_directed_edge(G, last_train_id, t, n_class, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < f[i][0].size(); j++) {
        if (j + 1 < f[i][0].size()) {
          add_directed_edge(G, f[i][0][j].second, f[i][0][j + 1].second, n_class, 0);
        }
      }

      for (const auto& p : f[i][1]) {
        int t = p.first;
        add_directed_edge(G, p.second, f[i][0][t].second, 1, 0);
      }
    }

    for (int i = 0; i < n - 1; i++) {
      for (const train& t : T[i]) {
        add_directed_edge(G, f[i][0][t.t1].second, f[i + 1][1][t.t2].second, 1, t.cost);
      }
    }

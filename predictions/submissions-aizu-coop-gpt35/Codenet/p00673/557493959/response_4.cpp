#include <cstdio>
#include <algorithm>
#include <cstring>
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

void add_directed_edge(edge *G, int *G_count, int u, int v, int capa, int cost) {
  G[G_count[u]++] = {v, G_count[v], capa, cost, 0};
  G[G_count[v]++] = {u, G_count[u] - 1, 0, -cost, 0};
}

pair<int, int> augment(int n, edge *G, int *G_count, int s, int t, int *pot) {
  static int pre[V_MAX];
  static int d[V_MAX];
  rep(u, n) d[u] = (u == s ? 0 : COST_INF);
  bool ok = false;
  static bool in_queue[V_MAX];
  memset(in_queue, false, sizeof(in_queue));
  static int Q[V_MAX];
  int front = 0;
  int back = 0;
  Q[back++] = s;
  in_queue[s] = true;
  while (front < back) {
    int u = Q[front++];
    in_queue[u] = false;
    if (u == t)
      ok = true;
    for (int i = 0; i < G_count[u]; i++) {
      edge &e = G[i];
      int cost2 = d[u] + e.cost + pot[u] - pot[e.v];
      if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
        d[e.v] = cost2;
        pre[e.v] = e.rev;
        if (!in_queue[e.v]) {
          in_queue[e.v] = true;
          Q[back++] = e.v;
        }
      }
    }
  }
  if (!ok)
    return make_pair(0, 0);
  int water = CAPA_INF;
  for (int v = t; v != s;) {
    edge &e1 = G[pre[v]];
    edge &e2 = G[e1.v];
    water = min(water, e2.capa - e2.flow);
    v = e1.v;
  }
  int cost = 0;
  for (int v = t; v != s;) {
    edge &e1 = G[pre[v]];
    edge &e2 = G[e1.v];
    e1.flow -= water;
    e2.flow += water;
    cost += water * e2.cost;
    v = e1.v;
  }
  rep(u, n) pot[u] += d[u];
  return make_pair(water, cost);
}

pair<int, int> primal_dual(int n, edge *G, int *G_count, int s, int t) {
  int ans1 = 0;
  int ans2 = 0;
  static int pot[V_MAX];
  while (1) {
    pair<int, int> tmp = augment(n, G, G_count, s, t, pot);
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
    train T[99][99];
    int m;
    rep(i, n - 1) {
      scanf("%d", &m);
      rep(j, m) scanf("%d%d%d", &T[i][j].t1, &T[i][j].t2, &T[i][j].cost);
    }
    int n_class;
    scanf("%d", &n_class);
    int V = 0;
    int f[100][2][10000];
    memset(f, -1, sizeof(f));
    rep(i, n - 1) rep(j, m) {
      int t1 = T[i][j].t1, t2 = T[i][j].t2;
      if (f[i][0][t1] == -1)
        f[i][0][t1] = V++;
      if (f[i + 1][0][t2] == -1)
        f[i + 1][0][t2] = V++;
      if (f[i + 1][1][t2] == -1)
        f[i + 1][1][t2] = V++;
    }
    int s = V++;
    int t = V++;
    static edge G[V_MAX];
    int G_count[V_MAX];
    memset(G_count, 0, sizeof(G_count));
    add_directed_edge(G, G_count, s, f[0][0][0], n_class, 0);
    add_directed_edge(G, G_count, f[n - 1][0][0], t, n_class, 0);
    rep(i, n) {
      for (int t = 0; t < 10000; t++) {
        if (f[i][0][t] != -1 && f[i][0][t + 1] != -1) {
          add_directed_edge(G, G_count, f[i][0][t], f[i][0][t + 1], n_class, 0);
        }
      }
      for (int t = 0; t < 10000; t++) {
        if (f[i][1][t] != -1 && f[i][0][t] != -1) {
          add_directed_edge(G, G_count, f[i][1][t], f[i][0][t], 1, 0);
        }
      }
    }
    rep(i, n - 1) rep(j, m) {
      add_directed_edge(G, G_count, f[i][0][T[i][j].t1], f[i + 1][1][T[i][j].t2], 1, T[i][j].cost);
    }
    pair<int, int> ans = primal_dual(V, G, G_count, s, t);
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}
#include <cstdio>
#include <unordered_map>
#include <queue>
#include <array>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
constexpr int V_MAX = 6000;
constexpr int CAPA_INF = 1 << 29;
constexpr int COST_INF = 1 << 29;
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
// ... rest of the code ...
int main() {
  for (int n; scanf("%d", &n), n;) {
    vector<train> T[99];
    rep(i, n - 1) {
      int m;
      scanf("%d", &m);
      T[i].reserve(m);
      rep(j, m) scanf("%d%d%d", &T[i][j].t1, &T[i][j].t2, &T[i][j].cost);
    }
    // ... rest of the code ...
    unordered_map<int, int> f[100][2];
    unordered_map<int, int>::iterator it, jt;
    rep(i, n - 1) rep(j, T[i].size()) {
      int t1 = T[i][j].t1, t2 = T[i][j].t2;
      f[i][0].emplace(t1, V++);
      f[i + 1][0].emplace(t2, V++);
      f[i + 1][1].emplace(t2, V++);
    }
    // ... rest of the code ...
  }
  return 0;
}
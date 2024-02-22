#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
  G[u].emplace_back((edge<T, U>){v, static_cast<int>(G[v].size()), capa, cost, 0});
  G[v].emplace_back((edge<T, U>){u, static_cast<int>(G[u].size() - 1), 0, -cost, 0});
}

// ... rest of the code

int main() {
  for (int n; scanf("%d", &n), n;) {
    vector<train> T[99];
    rep(i, n - 1) {
      int m;
      scanf("%d", &m);
      T[i].resize(m);
      for (auto& t : T[i]) scanf("%d%d%d", &t.t1, &t.t2, &t.cost);
    }

    // ... rest of the code
}
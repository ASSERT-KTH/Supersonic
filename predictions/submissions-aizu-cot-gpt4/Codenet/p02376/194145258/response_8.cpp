#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 29)
#define max_n 10000
using namespace std;
struct edge {
  int to, cap, rev;
};
struct node_t {
  node_t *pp, *lp, *rp;
  int id, val, mini, minId, lazy;
  edge *e;
  node_t(int id, int v) : id(id), val(v) {
    pp = lp = rp = NULL;
    lazy = 0;
    update();
  }
  inline void update() {
    mini = val, minId = id;
    if (lp && mini > lp->mini)
      mini = lp->mini, minId = lp->minId;
    if (rp && mini > rp->mini)
      mini = rp->mini, minId = rp->minId;
  }
  inline void apply(int v) { lazy += v, val += v, mini += v; }
  inline void push() {
    if (lazy != 0) {
      if (lp)
        lp->apply(lazy);
      if (rp)
        rp->apply(lazy);
      lazy = 0;
    }
  }
  /* rest of the code remains the same */

vector<edge> g[max_n];
vector<node_t*> nodes(max_n);
vector<int> lists[max_n];
std::vector<node_t> nodePool;

/* The rest of the code remains the same */

int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    fill(ptr, ptr + max_n, 0);
    nodePool.clear();
    for (int i = 0; i < n; i++)
      nodes[i] = &nodePool.emplace_back(i, INF);
    /* The rest of the code remains the same */
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int e, a, b, c;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  cout << max_flow(0, n - 1) << "\n";
  return 0;
}
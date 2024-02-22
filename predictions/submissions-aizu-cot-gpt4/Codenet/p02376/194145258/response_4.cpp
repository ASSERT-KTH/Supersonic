#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 29)
#define max_n 10000

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

  void update() {
    mini = val, minId = id;
    if (lp && mini > lp->mini)
      mini = lp->mini, minId = lp->minId;
    if (rp && mini > rp->mini)
      mini = rp->mini, minId = rp->minId;
  }
  void apply(int v) { lazy += v, val += v, mini += v; }
  void push() {
    if (lp)
      lp->apply(lazy);
    if (rp)
      rp->apply(lazy);
    lazy = 0;
  }
  bool is_root() { return !pp || (pp->lp != this && pp->rp != this); }
  void rotr();
  void rotl();
  void splay();
};

std::vector<edge> g[max_n];
int dist[max_n];
int n, ptr[max_n];
node_t *nodes[max_n];
std::vector<int> lists[max_n];

//... Rest of your functions ....

int main() {
  int e, a, b, c;
  std::cin >> n >> e;
  for (int i = 0; i < e; i++) {
    std::cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  std::cout << max_flow(0, n - 1) << "\n";
  return 0;
}
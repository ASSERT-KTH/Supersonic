#include <bits/stdc++.h>
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
  node_t() : id(0), val(0) {
    pp = lp = rp = NULL;
    lazy = 0;
    mini = INF;
  }
  // remains the same...
};
node_t node_pool[max_n];
node_t* new_node(int id, int v) {
  node_t *node = &node_pool[id];
  node->id = id; node->val = v; node->mini = v;
  node->lp = node->rp = node->pp = NULL;
  node->lazy = 0;
  return node;
}
// remains the same...
int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    fill(ptr, ptr + max_n, 0);
    for (int i = 0; i < n; i++)
      nodes[i] = new_node(i, INF);
    // remains the same...
  }
  return flow;
}
int main(void) {
  ios::sync_with_stdio(false);
  int e, a, b, c;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  cout << max_flow(0, n - 1) << "\n";
  return 0;
}
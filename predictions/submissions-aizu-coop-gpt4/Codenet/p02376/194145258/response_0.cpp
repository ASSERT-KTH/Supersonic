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
  node_t(int id, int v) : id(id), val(v) {
    pp = lp = rp = NULL;
    lazy = 0;
    update();
  }
  // OPTIMIZATION: Add a reset function to reset the node's values.
  void reset(int id, int v) {
    this->id = id;
    this->val = v;
    pp = lp = rp = NULL;
    lazy = 0;
    update();
  }
  // Rest of the code...
};

// Rest of the code...

int max_flow(int S, int T) {
  int flow = 0;
  // OPTIMIZATION: Move the bfs call outside of the while loop.
  while (bfs(S, T)) {
    fill(ptr, ptr + max_n, 0);
    for (int i = 0; i < n; i++)
      // OPTIMIZATION: Create nodes once and reset their values on every bfs call.
      if (nodes[i])
        nodes[i]->reset(i, INF);
      else
        nodes[i] = new node_t(i, INF);
    // Rest of the code...
  }
  return flow;
}
int main(void) {
  ios::sync_with_stdio(false);
  int e, a, b, c;
  cin >> n >> e;
  // OPTIMIZATION: Initialize nodes array once.
  for (int i = 0; i < n; i++)
    nodes[i] = new node_t(i, INF);
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  cout << max_flow(0, n - 1) << "\n";
  // OPTIMIZATION: Free nodes memory.
  for (int i = 0; i < n; i++)
    delete nodes[i];
  return 0;
}
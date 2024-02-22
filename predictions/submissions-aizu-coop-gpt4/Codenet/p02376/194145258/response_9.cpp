#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = (1 << 29);
const int max_n = 10000;

struct edge {
  int to, cap, rev;
};

struct node_t {
  node_t *pp, *lp, *rp;
  int id, val, mini, minId, lazy;
  edge *e;
  node_t(int id, int v) : id(id), val(v), pp(NULL), lp(NULL), rp(NULL), lazy(0) {
    update();
  }
  // rest of the code remains the same
};

node_t nodes_pool[max_n];

// rest of the code remains the same

int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    memset(ptr, 0, sizeof(ptr));
    for (int i = 0; i < n; i++)
      nodes_pool[i] = node_t(i, INF);
    node_t *s = &nodes_pool[S], *t = &nodes_pool[T];

    // rest of the code remains the same
  }
  return flow;
}

int main() {
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
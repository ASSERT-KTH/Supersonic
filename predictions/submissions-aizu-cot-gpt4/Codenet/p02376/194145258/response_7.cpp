#include <bits/stdc++.h>
#define INF (1 << 29)
#define max_n 10000
using namespace std;
struct edge {
  int to, cap, rev;
};
struct node_t {
  //...
  // Rest of the code remains unchanged
  //...
};

node_t *expose(node_t *x) {
  //...
  // Rest of the code remains unchanged
  //...
}

inline node_t *find_root(node_t *x) {
  expose(x);
  while (x->lp)
    x = x->lp;
  return x;
}

inline void cut(node_t *c) {
  expose(c);
  node_t *p = c->lp;
  c->lp = NULL;
  p->pp = NULL;
  c->val = INF;
}

inline void link(node_t *c, node_t *p, int val, edge *e) {
  expose(c), expose(p);
  c->pp = p, p->rp = c;
  c->val = val;
  c->update();
  c->e = e;
}

inline int minId(node_t *x) {
  expose(x);
  return x->minId;
}

inline void add(node_t *x, int val) {
  expose(x);
  x->apply(val);
}

vector<edge> g[max_n];
void add_edge(int from, int to, int cap) {
  g[from].push_back((edge){to, cap, g[to].size()});
  g[to].push_back((edge){from, 0, g[from].size() - 1});
}

int dist[max_n];
bool bfs(int s, int t) {
  queue<int> que;
  que.push(s);
  dist[s] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u == t)
      return true;
    for (int j = 0; j < g[u].size(); j++) {
      edge e = g[u][j];
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        que.push(e.to);
      }
    }
  }
  return false;
}

int n, ptr[max_n];
node_t *nodes[max_n];
vector<int> lists[max_n];
bool pour(int id, int i) {
  //...
  // Rest of the code remains unchanged
  //...
}

int max_flow(int S, int T) {
  for (int i = 0; i < n; i++)
    nodes[i] = new node_t(i, INF);
  int flow = 0;
  while (bfs(S, T)) {
    for (int i = 0; i < n; i++) {
      ptr[i] = 0;
      nodes[i]->reset(i, INF);
      lists[i].clear();
    }
    //...
    // Rest of the code remains unchanged
    //...
  }
  return flow;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int e, a, b, c;
  cin >> n >> e;
  for (int i = 0; i < n; i++) 
    g[i].reserve(max_n);
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  cout << max_flow(0, n - 1) << "\n";
  return 0;
}
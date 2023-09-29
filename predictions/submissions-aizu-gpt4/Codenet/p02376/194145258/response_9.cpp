#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#define INF (std::numeric_limits<int>::max() / 2)

struct Edge {
  int to, cap, rev;
};

struct Node {
  Node* pp = nullptr;
  Node* lp = nullptr;
  Node* rp = nullptr;
  int id = 0;
  int val = INF;
  int mini = INF;
  int minId = 0;
  int lazy = 0;
  Edge* e = nullptr;

  inline void update() {
    mini = val, minId = id;
    if (lp && mini > lp->mini)
      mini = lp->mini, minId = lp->minId;
    if (rp && mini > rp->mini)
      mini = rp->mini, minId = rp->minId;
  }
  inline void apply(int v) { lazy += v, val += v, mini += v; }
  inline void push() {
    if (lp)
      lp->apply(lazy);
    if (rp)
      rp->apply(lazy);
    lazy = 0;
  }
  bool is_root() { return !pp || (pp->lp != this && pp->rp != this); }
};

std::vector<Edge> g[10000];
int dist[10000];
Node* nodes[10000];
std::vector<int> lists[10000];
int ptr[10000];

Node* expose(Node* x) {
  Node* rp = nullptr;
  for (Node* p = x; p; p = p->pp) {
    p->update();
    p->rp = rp;
    rp = p;
  }
  x->update();
  return rp;
}

inline Node* find_root(Node* x) {
  expose(x);
  while (x->lp)
    x = x->lp;
  return x;
}

inline void cut(Node* c) {
  expose(c);
  Node* p = c->lp;
  c->lp = nullptr;
  p->pp = nullptr;
  c->val = INF;
}

inline void link(Node* c, Node* p, int val, Edge* e) {
  expose(c);
  expose(p);
  c->pp = p; 
  p->rp = c;
  c->val = val;
  c->update();
  c->e = e;
}

inline int minId(Node* x) {
  expose(x);
  return x->minId;
}

inline void add(Node* x, int val) {
  expose(x);
  x->apply(val);
}

void add_edge(int from, int to, int cap) {
  g[from].push_back({to, cap, (int)g[to].size()});
  g[to].push_back({from, 0, (int)g[from].size() - 1});
}

bool bfs(int s, int t) {
  std::fill(dist, dist + 10000, -1);
  dist[s] = 0;
  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u == t) return true;
    for (Edge& e : g[u]) {
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        que.push(e.to);
      }
    }
  }
  return false;
}

bool pour(int id, int i) {
  int u = lists[id][i];
  if (find_root(nodes[u]) == nodes[u])
    return true;
  Edge* e = nodes[u]->e;
  expose(nodes[u]);
  int df = e->cap - nodes[u]->val;
  e->cap -= df;
  g[e->to][e->rev].cap += df;
  return false;
}

int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    std::fill(ptr, ptr + 10000, 0);
    for (int i = 0; i < 10000; i++)
      nodes[i] = new Node{i, INF};
    Node* s = nodes[S]; 
    Node* t = nodes[T];
    for (int i = 0; i < 10000; i++)
      lists[i].clear();
    while (true) {
      Node* v = find_root(s);
      if (v == t) {
        expose(v = nodes[minId(s)]);
        flow += v->mini;
        add(s, -v->mini);
        while (true) {
          expose(v = nodes[minId(s)]);
          if (v->val > 0)
            break;
          g[v->e->to][v->e->rev].cap += v->e->cap;
          v->e->cap = 0;
          cut(v);
        }
        continue;
      }
      if (ptr[v->id] < g[v->id].size()) {
        Edge& e = g[v->id][ptr[v->id]++];
        if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
          link(v, nodes[e.to], e.cap, &e);
          lists[e.to].push_back(v->id);
        }
      } else {
        if (v == s) break;
        for (int i : lists[v->id]) {
          if (!pour(v->id, i))
            cut(nodes[i]);
        }
        lists[v->id].clear();
      }
    }
    for (int i = 0; i < 10000; i++) 
      delete nodes[i];
  }
  return flow;
}

int main() {
  std::ios::sync_with_stdio(false);
  int e, a, b, c;
  std::cin >> e;
  for (int i = 0; i < e; i++) {
    std::cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  std::cout << max_flow(0, e - 1) << "\n";
  return 0;
}
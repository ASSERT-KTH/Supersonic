#include <vector>
#include <queue>
#include <iostream>
#define INF (1 << 29)
#define MAX_N 10000

struct Edge {
  int to, cap, rev;
};

struct Node {
  Node *pp, *lp, *rp;
  int id, val, mini, minId, lazy;
  Edge *e;
  Node(int id, int v) : id(id), val(v), pp(NULL), lp(NULL), rp(NULL), lazy(0) {
    update();
  }

  inline void update() {
    mini = val;
    minId = id;
    if (lp && mini > lp->mini) {
      mini = lp->mini;
      minId = lp->minId;
    }
    if (rp && mini > rp->mini) {
      mini = rp->mini;
      minId = rp->minId;
    }
  }

  inline void apply(int v) {
    lazy += v;
    val += v;
    mini += v;
  }

  inline void push() {
    if (lp) lp->apply(lazy);
    if (rp) rp->apply(lazy);
    lazy = 0;
  }

  inline bool is_root() {
    return !pp || (pp->lp != this && pp->rp != this);
  }

  inline void rotr() {
    Node *q = pp, *r = q->pp;
    push(); q->push();
    if ((q->lp = rp)) rp->pp = q;
    rp = q; q->pp = this;
    if ((pp = r)) {
      if (r->lp == q) r->lp = this;
      if (r->rp == q) r->rp = this;
    }
    q->update();
  }

  inline void rotl() {
    Node *q = pp, *r = q->pp;
    push(); q->push();
    if ((q->rp = lp)) lp->pp = q;
    lp = q; q->pp = this;
    if ((pp = r)) {
      if (r->lp == q) r->lp = this;
      if (r->rp == q) r->rp = this;
    }
    q->update();
  }

  inline void splay() {
    while (!is_root()) {
      Node *q = pp;
      if (q->is_root()) {
        if (q->lp == this) rotr();
        else rotl();
      } else {
        Node *r = q->pp;
        if (r->lp == q) {
          if (q->lp == this) { q->rotr(); rotr(); }
          else { rotl(); rotr(); }
        } else {
          if (q->rp == this) { q->rotl(); rotl(); }
          else { rotr(); rotl(); }
        }
      }
    }
    push();
    update();
  }
};

inline Node* expose(Node *x) {
  Node *rp = NULL;
  for (Node *p = x; p; p = p->pp) {
    p->splay();
    p->rp = rp;
    rp = p;
  }
  x->splay();
  x->update();
  return rp;
}

inline Node* find_root(Node *x) {
  expose(x);
  while (x->lp) x = x->lp;
  return x;
}

inline void cut(Node *c) {
  expose(c);
  Node *p = c->lp;
  c->lp = NULL;
  p->pp = NULL;
  c->val = INF;
}

inline void link(Node *c, Node *p, int val, Edge *e) {
  expose(c); expose(p);
  c->pp = p; p->rp = c;
  c->val = val;
  c->update();
  c->e = e;
}

inline int minId(Node *x) {
  expose(x);
  return x->minId;
}

inline void add(Node *x, int val) {
  expose(x);
  x->apply(val);
}

std::vector<Edge> g[MAX_N];
void add_edge(int from, int to, int cap) {
  g[from].push_back((Edge){to, cap, (int)g[to].size()});
  g[to].push_back((Edge){from, 0, (int)g[from].size() - 1});
}

int dist[MAX_N];
bool bfs(int s, int t) {
  std::fill(dist, dist + MAX_N, -1);
  dist[s] = 0;
  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front(); que.pop();
    if (u == t) return true;
    for (int j = 0; j < (int)g[u].size(); j++) {
      Edge &e = g[u][j];
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        que.push(e.to);
      }
    }
  }
  return false;
}

int n, ptr[MAX_N];
Node *nodes[MAX_N];
std::vector<int> lists[MAX_N];

bool pour(int id, int i) {
  int u = lists[id][i];
  if (find_root(nodes[u]) == nodes[u]) return true;
  Edge *e = nodes[u]->e;
  expose(nodes[u]);
  int df = e->cap - nodes[u]->val;
  e->cap -= df;
  g[e->to][e->rev].cap += df;
  return false;
}

int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    std::fill(ptr, ptr + n, 0);
    for (int i = 0; i < n; i++) nodes[i] = new Node(i, INF);
    Node *s = nodes[S], *t = nodes[T];
    for (int i = 0; i < n; i++) lists[i].clear();
    while (true) {
      Node *v = find_root(s);
      if (v == t) {
        expose(v = nodes[minId(s)]);
        flow += v->mini;
        add(s, -v->mini);
        while (true) {
          expose(v = nodes[minId(s)]);
          if (v->val > 0) break;
          g[v->e->to][v->e->rev].cap += v->e->cap;
          v->e->cap = 0;
          cut(v);
        }
        continue;
      }
      if (ptr[v->id] < (int)g[v->id].size()) {
        Edge &e = g[v->id][ptr[v->id]++];
        if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
          link(v, nodes[e.to], e.cap, &e);
          lists[e.to].push_back(v->id);
        }
      } else {
        if (v == s) {
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)lists[i].size(); j++)
              pour(i, j);
            lists[i].clear();
          }
          break;
        }
        for (int i = 0; i < (int)lists[v->id].size(); i++) {
          if (!pour(v->id, i)) cut(nodes[lists[v->id][i]]);
        }
        lists[v->id].clear();
      }
    }
  }
  return flow;
}

int main(void) {
  int e, a, b, c;
  std::cin >> n >> e;
  for (int i = 0; i < e; i++) {
    std::cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  std::cout << max_flow(0, n - 1) << "\n";
  return 0;
}
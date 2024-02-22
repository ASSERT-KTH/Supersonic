#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;
const int max_n = 10000;

struct edge;
struct node_t;

struct node_t {
  node_t *pp, *lp, *rp;
  int id, val, mini, minId, lazy;
  edge *e;
  
  node_t(int id, int v) : id(id), val(v) {
    pp = lp = rp = nullptr;
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
  
  void rotr() {
    node_t *q = pp, *r = q->pp;
    q->push(), push();
    if ((q->lp = rp))
      rp->pp = q;
    rp = q;
    q->pp = this;
    if ((pp = r)) {
      if (r->lp == q)
        r->lp = this;
      if (r->rp == q)
        r->rp = this;
    }
    q->update();
  }
  
  void rotl() {
    node_t *q = pp, *r = q->pp;
    q->push(), push();
    if ((q->rp = lp))
      lp->pp = q;
    lp = q;
    q->pp = this;
    if ((pp = r)) {
      if (r->lp == q)
        r->lp = this;
      if (r->rp == q)
        r->rp = this;
    }
    q->update();
  }
  
  void splay() {
    while (!is_root()) {
      node_t *q = pp;
      if (q->is_root()) {
        if (q->lp == this)
          rotr();
        else
          rotl();
      } else {
        node_t *r = q->pp;
        if (r->lp == q) {
          if (q->lp == this) {
            q->rotr();
            rotr();
          } else {
            rotl();
            rotr();
          }
        } else {
          if (q->rp == this) {
            q->rotl();
            rotl();
          } else {
            rotr();
            rotl();
          }
        }
      }
    }
    push();
    update();
  }
};

struct edge {
  int to, cap, rev;
};

std::vector<edge> g[max_n];
std::vector<int> dist(max_n);
std::vector<int> ptr(max_n);
std::vector<node_t*> nodes(max_n);
std::vector<std::vector<int>> lists(max_n);

void add_edge(int from, int to, int cap) {
  g[from].emplace_back(edge{to, cap, g[to].size()});
  g[to].emplace_back(edge{from, 0, g[from].size() - 1});
}

bool bfs(int s, int t) {
  std::fill(dist.begin(), dist.end(), -1);
  dist[s] = 0;
  std::vector<int> que;
  que.push_back(s);
  
  int front = 0;
  while (front < que.size()) {
    int u = que[front++];
    if (u == t)
      return true;
    for (const auto& e : g[u]) {
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        que.push_back(e.to);
      }
    }
  }
  
  return false;
}

int minId(node_t *x) {
  x->splay();
  return x->minId;
}

void add(node_t *x, int val) {
  x->splay();
  x->apply(val);
}

int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    for (int i = 0; i < max_n; i++)
      nodes[i] = new node_t(i, INF);
    
    node_t *s = nodes[S], *t = nodes[T];
    for (int i = 0; i < max_n; i++)
      lists[i].clear();
    
    while (true) {
      node_t *v = s;
      while (true) {
        v->splay();
        if (v->rp == nullptr)
          break;
        v = v->rp;
      }
      
      if (v == t) {
        v->splay();
        flow += v->mini;
        add(s, -v->mini);
        while (true) {
          v->splay();
          if (v->val > 0)
            break;
          g[v->e->to][v->e->rev].cap += v->e->cap;
          v->e->cap = 0;
          v->splay();
          if (v->lp)
            v->lp->rp = nullptr;
          v->lp = nullptr;
        }
        continue;
      }
      
      if (ptr[v->id] < g[v->id].size()) {
        edge& e = g[v->id][ptr[v->id]++];
        if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
          node_t* c = nodes[e.to];
          c->splay();
          c->pp = v;
          c->val = e.cap;
          c->update();
          c->e = &e;
          lists[e.to].push_back(v->id);
        }
      } else {
        if (v == s) {
          for (int i = 0; i < max_n; i++) {
            for (int j = 0; j < lists[i].size(); j++)
              pour(i, j);
            lists[i].clear();
          }
          break;
        }
        
        for (int i = 0; i < lists[v->id].size(); i++) {
          if (!pour(v->id, i))
            cut(nodes[lists[v->id][i]]);
        }
        lists[v->id].clear();
      }
    }
  }
  
  return flow;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  
  int n, e, a, b, c;
  std::cin >> n >> e;
  
  for (int i = 0; i < e; i++) {
    std::cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  
  std::cout << max_flow(0, n - 1) << "\n";
  
  return 0;
}
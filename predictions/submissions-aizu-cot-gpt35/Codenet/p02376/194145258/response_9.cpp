#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
const int max_n = 10000;

struct edge {
  int to, cap, rev;
};

struct node_t {
  node_t *lp, *rp;
  int id, val, mini, minId, lazy;
  edge *e;
  
  node_t(int id, int v) : id(id), val(v) {
    lp = rp = nullptr;
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
  
  bool is_root() { return !lp && !rp; }
  
  void rotr() {
    node_t *q = lp, *r = q->rp;
    q->push(), push();
    if ((q->rp = this))
      rp->lp = q;
    lp = q;
    q->rp = this;
    if ((rp = r)) {
      if (r->lp == this)
        r->lp = this;
      if (r->rp == this)
        r->rp = this;
    }
    q->update();
  }
  
  void rotl() {
    node_t *q = rp, *r = q->lp;
    q->push(), push();
    if ((q->lp = this))
      lp->rp = q;
    rp = q;
    q->lp = this;
    if ((rp = r)) {
      if (r->lp == this)
        r->lp = this;
      if (r->rp == this)
        r->rp = this;
    }
    q->update();
  }
  
  void splay() {
    while (!is_root()) {
      node_t *q = lp;
      if (q->is_root()) {
        if (q->lp == this)
          rotr();
        else
          rotl();
      } else {
        node_t *r = q->rp;
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

node_t *expose(node_t *x) {
  node_t *rp = nullptr;
  for (node_t *p = x; p; p = p->lp) {
    p->splay();
    p->rp = rp;
    p->update();
    rp = p;
  }
  x->splay();
  return rp;
}

node_t *find_root(node_t *x) {
  expose(x);
  while (x->rp)
    x = x->rp;
  return x;
}

void cut(node_t *c) {
  expose(c);
  node_t *p = c->lp;
  c->lp = nullptr;
  p->rp = nullptr;
  c->val = INF;
}

void link(node_t *c, node_t *p, int val, edge *e) {
  expose(c), expose(p);
  c->lp = p, p->rp = c;
  c->val = val;
  c->e = e;
}

void add(node_t *x, int val) {
  expose(x);
  x->apply(val);
}

vector<edge> g[max_n];

void add_edge(int from, int to, int cap) {
  g[from].push_back({to, cap, static_cast<int>(g[to].size())});
  g[to].push_back({from, 0, static_cast<int>(g[from].size()) - 1});
}

bool bfs(int s, int t) {
  vector<int> dist(max_n, -1);
  dist[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (u == t)
      return true;
    for (const edge &e : g[u]) {
      if (dist[e.to] < 0 && e.cap > 0) {
        dist[e.to] = dist[u] + 1;
        que.push(e.to);
      }
    }
  }
  return false;
}

int max_flow(int S, int T) {
  int flow = 0;
  while (bfs(S, T)) {
    for (int i = 0; i < max_n; i++)
      g[i].clear();
      
    for (int i = 0; i < n; i++)
      for (int j = 0; j < lists[i].size(); j++)
        cut(nodes[lists[i][j]]);
        
    fill(lists, lists + max_n, vector<int>());
    fill(ptr, ptr + max_n, 0);
    
    for (int i = 0; i < n; i++)
      nodes[i] = new node_t(i, INF);
    
    node_t *s = nodes[S], *t = nodes[T];
    
    while (true) {
      node_t *v = find_root(s);
      if (v == t) {
        expose(v = nodes[s->minId]);
        flow += v->mini;
        add(s, -v->mini);
        while (true) {
          expose(v = nodes[s->minId]);
          if (v->val > 0)
            break;
          g[v->e->to][v->e->rev].cap += v->e->cap;
          v->e->cap = 0;
          cut(v);
        }
        continue;
      }
      if (v->id < g[v->id].size()) {
        edge &e = g[v->id][v->id++];
        if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
          link(v, nodes[e.to], e.cap, &e);
          lists[e.to].push_back(v->id);
        }
      } else {
        if (v == s) {
          for (int i = 0; i < n; i++) {
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
  ios::sync_with_stdio(false);
  int n, e, a, b, c;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  cout << max_flow(0, n - 1) << "\n";
  return 0;
}
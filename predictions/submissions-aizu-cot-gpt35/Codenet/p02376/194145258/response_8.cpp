#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000
#define MAX_N 10000

using namespace std;

struct edge {
  int to, cap, rev;
};

class Node {
public:
  Node *pp, *lp, *rp;
  int id, val, mini, minId, lazy;
  edge *e;

  Node(int id, int v) : id(id), val(v) {
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

  void apply(int v) {
    lazy += v, val += v, mini += v;
  }

  void push() {
    if (lp)
      lp->apply(lazy);
    if (rp)
      rp->apply(lazy);
    lazy = 0;
  }

  bool is_root() {
    return !pp || (pp->lp != this && pp->rp != this);
  }

  void rotr() {
    Node *q = pp, *r = q->pp;
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
    Node *q = pp, *r = q->pp;
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
      Node *q = pp;
      if (q->is_root()) {
        if (q->lp == this)
          rotr();
        else
          rotl();
      } else {
        Node *r = q->pp;
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

Node *expose(Node *x) {
  Node *rp = NULL;
  for (Node *p = x; p; p = p->pp) {
    p->splay();
    p->rp = rp;
    p->update();
    rp = p;
  }
  x->splay();
  return rp;
}

Node *find_root(Node *x) {
  expose(x);
  while (x->lp)
    x = x->lp;
  return x;
}

void cut(Node *c) {
  expose(c);
  Node *p = c->lp;
  c->lp = NULL;
  p->pp = NULL;
  c->val = INF;
}

void link(Node *c, Node *p, int val, edge *e) {
  expose(c), expose(p);
  c->pp = p, p->rp = c;
  c->val = val;
  c->update();
  c->e = e;
}

int minId(Node *x) {
  expose(x);
  return x->minId;
}

void add(Node *x, int val) {
  expose(x);
  x->apply(val);
}

vector<edge> g[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

bool bfs(int s, int t) {
  queue<int> que;
  que.push(s);
  dist[s] = 0;
  visited[s] = true;

  while (!que.empty()) {
    int u = que.front();
    que.pop();

    if (u == t)
      return true;

    for (edge &e : g[u]) {
      if (!visited[e.to] && e.cap > 0) {
        que.push(e.to);
        dist[e.to] = dist[u] + 1;
        visited[e.to] = true;
      }
    }
  }

  return false;
}

int max_flow(int S, int T) {
  int flow = 0;

  while (bfs(S, T)) {
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    Node nodes[MAX_N];
    int ptr[MAX_N];
    vector<int> lists[MAX_N];

    for (int i = 0; i < MAX_N; i++)
      ptr[i] = 0;

    Node *s = &nodes[S], *t = &nodes[T];

    while (true) {
      Node *v = find_root(s);

      if (v == t) {
        expose(v = &nodes[minId(s)]);
        flow += v->mini;
        add(s, -v->mini);

        while (true) {
          expose(v = &nodes[minId(s)]);
          if (v->val > 0)
            break;

          g[v->e->to][v->e->rev].cap += v->e->cap;
          v->e->cap = 0;
          cut(v);
        }

        continue;
      }

      if (ptr[v->id] < g[v->id].size()) {
        edge &e = g[v->id][ptr[v->id]++];
        if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
          link(v, &nodes[e.to], e.cap, &e);
          lists[e.to].push_back(v->id);
        }
      } else {
        if (v == s) {
          for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < lists[i].size(); j++)
              pour(i, j);
            lists[i].clear();
          }
          break;
        }

        for (int i = 0; i < lists[v->id].size(); i++) {
          if (!pour(v->id, i))
            cut(&nodes[lists[v->id][i]]);
        }

        lists[v->id].clear();
      }
    }
  }

  return flow;
}

void add_edge(int from, int to, int cap) {
  g[from].push_back({to, cap, g[to].size()});
  g[to].push_back({from, 0, g[from].size() - 1});
}

int main() {
  int n, e, a, b, c;
  scanf("%d %d", &n, &e);

  for (int i = 0; i < e; i++) {
    scanf("%d %d %d", &a, &b, &c);
    add_edge(a, b, c);
  }

  printf("%d\n", max_flow(0, n - 1));
  return 0;
}
#include <vector>
#include <queue>
#include <algorithm>

static constexpr int INF = (1 << 29);
static constexpr int max_n = 10000;

struct edge {
    int to, cap, rev;
};

struct node_t {
    node_t *pp, *lp, *rp;
    int id, val, mini, minId, lazy;
    edge *e;

    node_t(int id, int v) : id(id), val(v), pp(nullptr), lp(nullptr), rp(nullptr), lazy(0), e(nullptr) {
        update();
    }

    inline void update() {
        mini = val, minId = id;
        if (lp && mini > lp->mini) mini = lp->mini, minId = lp->minId;
        if (rp && mini > rp->mini) mini = rp->mini, minId = rp->minId;
    }

    inline void apply(int v) { lazy += v, val += v, mini += v; }

    inline void push() {
        if (lp) lp->apply(lazy);
        if (rp) rp->apply(lazy);
        lazy = 0;
    }

    bool is_root() { return !pp || (pp->lp != this && pp->rp != this); }

    void rot(node_t*(&a), node_t*(&b), node_t*(&c), node_t*(&d)) {
        node_t *p = pp, *q = p->pp;
        p->push(), push();
        if ((p->*a = d)) d->pp = p;
        p->*b = this, pp = p;
        if ((pp = q)) {
            if (q->lp == p) q->lp = this;
            if (q->rp == p) q->rp = this;
        }
        p->update();
    }

    void splay() {
        while (!is_root()) {
            node_t *p = pp;
            if (p->is_root()) {
                p->lp == this ? rot(p->rp, p->lp, lp, rp) : rot(p->lp, p->rp, rp, lp);
            } else {
                auto a = p->pp;
                a->lp == p
                    ? (p->lp == this ? rot(a->rp, a->lp, p->rp, p->lp) : rot(a->rp, a->lp, p->lp, rp))
                    : (p->rp == this ? rot(a->lp, a->rp, p->lp, p->rp) : rot(a->lp, a->rp, rp, lp));
            }
        }
        push();
        update();
    }
};

node_t *expose(node_t *x) {
    node_t *rp = nullptr;
    for (node_t *p = x; p; p = p->pp) {
        p->splay();
        p->rp = rp;
        p->update();
        rp = p;
    }
    x->splay();
    return rp;
}

inline node_t *find_root(node_t *x) {
    expose(x);
    while (x->lp) x = x->lp;
    return x;
}

inline void cut(node_t *c) {
    expose(c);
    node_t *p = c->lp;
    c->lp = nullptr;
    p->pp = nullptr;
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

std::vector<edge> g[max_n];
void add_edge(int from, int to, int cap) {
    g[from].push_back({to, cap, (int)g[to].size()});
    g[to].push_back({from, 0, (int)g[from].size() - 1});
}

int dist[max_n];
bool bfs(int s, int t) {
    std::fill(dist, dist + max_n, -1);
    dist[s] = 0;
    std::queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        if (u == t) return true;
        for (edge &e : g[u]) {
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
std::vector<int> lists[max_n];

bool pour(int id, int i) {
    int u = lists[id][i];
    if (find_root(nodes[u]) == nodes[u]) return true;
    edge *e = nodes[u]->e;
    expose(nodes[u]);
    int df = e->cap - nodes[u]->val;
    e->cap -= df;
    g[e->to][e->rev].cap += df;
    return false;
}

int max_flow(int S, int T) {
    int flow = 0;
    while (bfs(S, T)) {
        std::fill(ptr, ptr + max_n, 0);
        for (int i = 0; i < n; i++)
            nodes[i] = new node_t(i, INF);
        node_t *s = nodes[S], *t = nodes[T];
        for (int i = 0; i < n; i++)
            lists[i].clear();
        while (true) {
            node_t *v = find_root(s);
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
                edge &e = g[v->id][ptr[v->id]++];
                if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
                    link(v, nodes[e.to], e.cap, &e);
                    lists[e.to].push_back(v->id);
                }
            } else {
                if (v == s) {
                    for (int i = 0; i < n; i++) {
                        for (int j : lists[i]) if (!pour(i, j)) cut(nodes[j]);
                        lists[i].clear();
                    }
                    break;
                }
                for (int i : lists[v->id]) if (!pour(v->id, i)) cut(nodes[i]);
                lists[v->id].clear();
            }
        }
    }
    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);
    int e, a, b, c;
    std::cin >> n >> e;
    for (int i = 0; i < e; i++) {
        std::cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    std::cout << max_flow(0, n - 1) << "\n";
    return 0;
}
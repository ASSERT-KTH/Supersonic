#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, N = 1e4;
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
node_t *expose(node_t *x) {
    node_t *rp = NULL;
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
vector<edge> g[N];
void add_edge(int from, int to, int cap) {
    g[from].push_back((edge){to, cap, g[to].size()});
    g[to].push_back((edge){from, 0, g[from].size() - 1});
}
int dist[N], ptr[N];
node_t *nodes[N];
vector<int> lists[N];
bool pour(int id, int i) {
    int u = lists[id][i];
    if (find_root(nodes[u]) == nodes[u])
        return true;
    edge *e = nodes[u]->e;
    expose(nodes[u]);
    int df = e->cap - nodes[u]->val;
    e->cap -= df;
    g[e->to][e->rev].cap += df;
    return false;
}
int max_flow(int S, int T) {
    int flow = 0;
    while (true) {
        fill(dist, dist + N, -1);
        dist[S] = 0;
        queue<int> que;
        que.push(S);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            if (u == T)
                goto bfs_end;
            for (int j = 0; j < g[u].size(); j++) {
                edge e = g[u][j];
                if (dist[e.to] < 0 && e.cap > 0) {
                    dist[e.to] = dist[u] + 1;
                    que.push(e.to);
                }
            }
        }
        return flow;
    bfs_end:
        fill(ptr, ptr + N, 0);
        for (int i = 0; i < N; i++)
            nodes[i] = new node_t(i, INF);
        node_t *s = nodes[S], *t = nodes[T];
        for (int i = 0; i < N; i++)
            lists[i].clear();
        while (true) {
            node_t *v = find_root(s);
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
                edge &e = g[v->id][ptr[v->id]++];
                if (dist[e.to] == dist[v->id] + 1 && e.cap > 0) {
                    link(v, nodes[e.to], e.cap, &e);
                    lists[e.to].push_back(v->id);
                }
            } else {
                if (v == s) {
                    for (int i = 0; i < N; i++) {
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
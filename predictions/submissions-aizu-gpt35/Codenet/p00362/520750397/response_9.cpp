#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1];
int idx = 0;

inline void addEdge(int u, int v, int w) {
    nxt[++idx] = head[u];
    head[u] = idx;
    to[idx] = v;
    val[idx] = w;
}

int n, k;
int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], rnk[MAXN], tim = 0;
int a[MAXN], c[MAXN], b[MAXN];
int seg[MAXN << 2], tag[MAXN << 2];

inline void pushUp(int p) {
    seg[p] = (seg[p << 1] + seg[p << 1 | 1]) % k;
}

inline void pushTag(int p, int l, int r, int w) {
    tag[p] += w % k;
    seg[p] += w % k * (r - l + 1);
    seg[p] %= k;
}

inline void pushDown(int p, int l, int r) {
    int mid = (l + r) >> 1;
    pushTag(p << 1, l, mid, tag[p]);
    pushTag(p << 1 | 1, mid + 1, r, tag[p]);
    tag[p] = 0;
}

void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = a[rnk[l]] % k;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushUp(p);
}

void modify(int p, int l, int r, int ql, int qr, int w) {
    if (ql <= l && r <= qr) {
        pushTag(p, l, r, w);
        return;
    }
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) modify(p << 1, l, mid, ql, qr, w);
    if (qr > mid) modify(p << 1 | 1, mid + 1, r, ql, qr, w);
    pushUp(p);
}

int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[p] % k;
    pushDown(p, l, r);
    int mid = (l + r) >> 1, res = 0;
    if (ql <= mid) res = (res + query(p << 1, l, mid, ql, qr) % k) % k;
    if (qr > mid) res = (res + query(p << 1 | 1, mid + 1, r, ql, qr) % k) % k;
    return res % k;
}

void dfs1(int u, int f, int depth) {
    dep[u] = depth;
    fa[u] = f;
    sz[u] = 1;
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = to[i];
        if (v == f) continue;
        c[v] = val[i];
        dfs1(v, u, depth + 1);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int topf) {
    top[u] = topf;
    dfn[u] = ++tim;
    rnk[tim] = u;
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = to[i];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int queryPath(int u, int v) {
    int ans = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans = (ans + query(1, 1, n, dfn[top[u]], dfn[u])) % k;
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans = (ans + query(1, 1, n, dfn[u], dfn[v])) % k;
    return ans;
}

void modifyPath(int u, int v, int w) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        modify(1, 1, n, dfn[top[u]], dfn[u], w);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    modify(1, 1, n, dfn[u], dfn[v], w);
}

int querySubtree(int u) {
    return query(1, 1, n, dfn[u], dfn[u] + sz[u] - 1) % k;
}

void modifySubtree(int u, int w) {
    modify(1, 1, n, dfn[u], dfn[u] + sz[u] - 1, w);
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    while (q--) {
        char op[2];
        int x, y;
        scanf("%s %d %d", op, &x, &y);
        if (op[0] == 'C') {
            modifySubtree(x, y);
        } else if (op[0] == 'N') {
            printf("%d\n", queryPath(x, y));
        } else {
            modifyPath(x, x, y);
        }
    }
    return 0;
}
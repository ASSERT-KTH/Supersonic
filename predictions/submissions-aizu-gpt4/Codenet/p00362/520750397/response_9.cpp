#include <bits/stdc++.h>
using namespace std;

typedef long long L;
const L N = 2e5 + 5;
L sz[N], hson[N], dep[N], p[N], w[N], n, m, tot, top[N], dfn[N], rnk[N], a[N], c[N], k;
char ss[N];
map<L, L> mp[N];

struct node {
    L l, r, sum, add;
};
node tree[N << 2];

void push_up(L x) {
    tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
}

void push_down(L x, L l, L r) {
    if (!tree[x].add) return;
    L mid = (l + r) >> 1;
    tree[x << 1].sum += tree[x].add * (mid - l + 1);
    tree[x << 1 | 1].sum += tree[x].add * (r - mid);
    tree[x << 1].add += tree[x].add;
    tree[x << 1 | 1].add += tree[x].add;
    tree[x].add = 0;
}

void build(L x, L l, L r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].add = 0;
    if (l == r) {
        tree[x].sum = c[rnk[l]] % k == 0 ? c[rnk[l]] : 0;
        return;
    }
    L mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    push_up(x);
}

void update(L x, L l, L r, L d) {
    if (l <= tree[x].l && tree[x].r <= r) {
        tree[x].sum += d * (tree[x].r - tree[x].l + 1);
        tree[x].add += d;
        return;
    }
    push_down(x, tree[x].l, tree[x].r);
    L mid = (tree[x].l + tree[x].r) >> 1;
    if (l <= mid) update(x << 1, l, r, d);
    if (r > mid) update(x << 1 | 1, l, r, d);
    push_up(x);
}

L query(L x, L l, L r) {
    if (l <= tree[x].l && tree[x].r <= r) return tree[x].sum;
    push_down(x, tree[x].l, tree[x].r);
    L mid = (tree[x].l + tree[x].r) >> 1;
    L sum = 0;
    if (l <= mid) sum += query(x << 1, l, r);
    if (r > mid) sum += query(x << 1 | 1, l, r);
    return sum;
}

void dfs1(L u, L fa, L depth) {
    dep[u] = depth;
    p[u] = fa;
    sz[u] = 1;
    for (auto v : mp[u]) {
        if (v.first == fa) continue;
        w[v.first] = v.second;
        dfs1(v.first, u, depth + 1);
        sz[u] += sz[v.first];
        if (sz[v.first] > sz[hson[u]]) hson[u] = v.first;
    }
}

void dfs2(L u, L topf) {
    top[u] = topf;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (!hson[u]) return;
    dfs2(hson[u], topf);
    for (auto v : mp[u]) {
        if (v.first == p[u] || v.first == hson[u]) continue;
        dfs2(v.first, v.first);
    }
}

L path_query(L x, L y) {
    L res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res += query(1, dfn[top[x]], dfn[x]);
        x = p[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    res += query(1, dfn[x], dfn[y]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (L i = 1, u, v, c; i < n; i++) {
        cin >> u >> v >> c;
        mp[u][v] = mp[v][u] = c;
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    for (L i = 1; i <= n; i++) {
        c[i] = (c[i - 1] + w[rnk[i]]) % k;
    }
    build(1, 1, n);
    L q;
    cin >> q;
    while (q--) {
        L a, b;
        cin >> ss >> a >> b;
        if (ss[0] == 'Q') {
            cout << path_query(a, b) << "\n";
        } else {
            L tmp = b - w[a];
            w[a] = b;
            if (p[a] != 0 && dfn[p[a]] < dfn[a]) update(1, dfn[a], dfn[a], tmp);
            if (hson[p[a]] == a) update(1, dfn[a], dfn[a] + sz[a] - 1, tmp);
        }
    }
    return 0;
}
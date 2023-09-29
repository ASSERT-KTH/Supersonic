#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
const int N = 200005;
const int LOGN = 20;
int n, q, cnt, head[N], to[N << 1], nxt[N << 1];
int dep[N], fa[N][LOGN];
inline void add(int u, int v) {
    to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt;
}
void dfs(int u, int f) {
    dep[u] = dep[f] + 1, fa[u][0] = f;
    for (int i = 1; i <= LOGN - 1; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == f) continue;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i, 1, n + 1) {
        int k;
        cin >> k;
        rep(j, 0, k) {
            int c;
            cin >> c;
            add(i, c);
            add(c, i);
        }
    }
    dfs(1, 0);
    cin >> q;
    rep(i, 0, q) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}
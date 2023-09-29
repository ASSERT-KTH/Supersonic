#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
vector<pair<ll, ll>> adj[MAXN];
ll a[MAXN], c[MAXN], h[MAXN], p[MAXN], s[MAXN], x[MAXN], z[MAXN], o[MAXN], b[MAXN];
int n, k;

void update(int i, ll val) {
    for (; i <= n; i += i & -i) b[i] += val;
}

ll query(int i) {
    ll sum = 0;
    for (; i > 0; i -= i & -i) sum += b[i];
    return sum;
}

void dfs1(int u, int par) {
    z[u] = 1;
    p[u] = par;
    for (auto it : adj[u]) {
        int v = it.first;
        if (v == par) continue;
        c[v] = it.second;
        h[v] = h[u] + 1;
        dfs1(v, u);
        z[u] += z[v];
        if (z[u] < z[v]) s[u] = v;
    }
}

void dfs2(int u, int head) {
    x[u] = ++k;
    o[k] = u;
    update(k, a[u]);
    if (s[u]) dfs2(s[u], head);
    for (auto it : adj[u]) {
        int v = it.first;
        if (v == p[u] || v == s[u]) continue;
        dfs2(v, v);
    }
}

ll solve(int u, int v) {
    ll res = 0;
    while (x[u] < x[v]) {
        res += query(x[u]) - query(x[v] + 1);
        u = p[u];
    }
    while (x[u] > x[v]) {
        res += query(x[u]) - query(x[v] + 1);
        v = p[v];
    }
    if (h[u] > h[v]) swap(u, v);
    res += query(x[u]) - query(x[v] + 1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1, u, v, c; i < n; ++i) {
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    dfs1(1, 0);
    dfs2(1, 1);

    int q;
    cin >> q;
    while (q--) {
        char type;
        int u, v;
        cin >> type >> u >> v;
        if (type == '+') {
            a[u] += v;
            update(x[u], v);
        } else {
            cout << solve(u, v) << "\n";
        }
    }

    return 0;
}
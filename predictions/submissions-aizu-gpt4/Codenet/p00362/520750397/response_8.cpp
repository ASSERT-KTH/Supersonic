#include <bits/stdc++.h>

using namespace std;

typedef long long L;

const int N = 2e5 + 5;
vector<pair<int, int>> g[N];
int u[N], sz[N], h[N], p[N], d[N], w[N], b[N], x[N], t[N];
L s[N], a[N];

void dfs(int v, int f = 0) {
    p[v] = f;
    sz[v] = 1;
    d[v] = d[f] + 1;
    for (auto i: g[v]) {
        if (i.first != f) {
            w[i.first] = i.second;
            dfs(i.first, v);
            sz[v] += sz[i.first];
            if (sz[i.first] > sz[h[v]]) h[v] = i.first;
        }
    }
}

void dfs2(int v, int f) {
    b[v] = (v == h[f] ? b[f] : v);
    x[v] = ++t[0];
    t[x[v]] = v;
    s[x[v]] = s[x[v - 1]] + a[v];
    if (h[v]) dfs2(h[v], v);
    for (auto i: g[v]) {
        if (i.first != h[v] && i.first != p[v]) dfs2(i.first, i.first);
    }
}

L get(int l, int r) {
    return s[r] - s[l - 1];
}

L solve(int v, int u) {
    L res = 0;
    while (b[v] != b[u]) {
        if (d[b[v]] < d[b[u]]) swap(v, u);
        res += get(x[b[v]], x[v]);
        v = p[b[v]];
    }
    if (d[v] > d[u]) swap(v, u);
    return res + get(x[v], x[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    L k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    dfs(1);
    dfs2(1);
    for (int i = 1; i <= n; ++i) a[x[i]] = a[x[i - 1]] + w[i];
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == '?') {
            int v, u;
            cin >> v >> u;
            cout << solve(v, u) << endl;
        } else {
            int v;
            L val;
            cin >> v >> val;
            L diff = val - w[v];
            w[v] = val;
            a[x[v]] += diff;
            for (int i = x[v]; i <= n; i += i & -i) s[i] += diff;
        }
    }
    return 0;
}
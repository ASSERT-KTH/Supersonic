#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 2e5+5;

struct edge {
    int v, w;
};

vector<edge> g[MAXN];
int sz[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], par[MAXN], depth[MAXN], cost[MAXN], bit[MAXN], arr[MAXN], timer = 0;
map<ll, ll> mp[MAXN];
ll k;

void dfs(int u, int p) {
    sz[u] = 1, par[u] = p, depth[u] = depth[p] + 1;
    for (auto &e : g[u]) {
        if (e.v == p) continue;
        cost[e.v] = e.w;
        dfs(e.v, u);
        sz[u] += sz[e.v];
        if (sz[e.v] > sz[heavy[u]]) heavy[u] = e.v;
    }
}

void decompose(int u, int h) {
    head[u] = h, pos[u] = ++timer, arr[timer] = u;
    if (heavy[u]) decompose(heavy[u], h);
    for (auto &e : g[u]) {
        if (e.v == par[u] || e.v == heavy[u]) continue;
        decompose(e.v, e.v);
    }
}

void add(int i, ll x) {
    for (; i <= timer; i += i & -i) {
        bit[i] += x;
    }
}

ll sum(int i) {
    ll ret = 0;
    for (; i; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}

void update(int u, ll x) {
    add(pos[u], x);
    add(pos[u] + sz[u], -x);
}

ll query(int u) {
    ll ret = 0;
    for (int v = u; v; v = par[head[v]]) {
        ret += sum(pos[v]) + 1LL * mp[head[v]][depth[u] % k] * cost[u];
        ret %= k;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    decompose(1, 1);
    for (int i = 1; i <= n; ++i) {
        mp[head[i]][depth[i] % k] += cost[i];
    }
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u, x; cin >> u >> x; 
            update(u, x);
        } else {
            int u; cin >> u; 
            cout << query(u) << "\n";
        }
    }
    return 0;
}
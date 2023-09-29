#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 200005
#define ll long long
using namespace std;

ll n, k, u, v, w, q, a, b, s[SIZE], t[SIZE], p[SIZE], h[SIZE], c[SIZE];
vector<pair<ll, ll>> edge[SIZE];
bool vis[SIZE];

void dfs(ll u) {
    vis[u] = true;
    for(auto i : edge[u]) {
        ll v = i.first, w = i.second;
        if(vis[v]) continue;
        h[v] = h[u] + 1;
        p[v] = u;
        c[v] = w;
        dfs(v);
    }
}

void update(ll u, ll v, ll x) {
    while(u != v) {
        if(h[u] < h[v]) swap(u, v);
        s[u] += x;
        u = p[u];
    }
}

ll query(ll u, ll v) {
    ll res = 0;
    while(u != v) {
        if(h[u] < h[v]) swap(u, v);
        res += (s[u] + t[u] + c[u]) % k == 0 ? s[u] + t[u] + c[u] : 0;
        u = p[u];
    }
    return res;
}

int main() {
    cin >> n >> k;
    for(ll i = 1; i < n; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dfs(1);
    cin >> q;
    while(q--) {
        char op;
        cin >> op >> a >> b;
        if(op == '+') update(a, b, 1);
        else cout << query(a, b) << '\n';
    }
    return 0;
}
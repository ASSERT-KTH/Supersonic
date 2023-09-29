#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
const int MAXN = 2e5 + 5;
const int INF = 1e18 + 7;
vector<int> G[MAXN];
int n, m, deg[MAXN], ans[MAXN], ptr;
bool vis[MAXN], flag;
void dfs(int v) {
    vis[v] = true;
    for (auto u : G[v]) {
        deg[u]--;
        if (deg[u] == 0 && !vis[u]) dfs(u);
    }
    ans[ptr--] = v;
}
void topsort() {
    ptr = n - 1;
    rep(v, n) if (deg[v] == 0 && !vis[v]) dfs(v);
    rep(i, n - 1) if (!vis[i] || deg[i] > 0 || G[ans[i]].empty() || find(G[ans[i]].begin(), G[ans[i]].end(), ans[i + 1]) == G[ans[i]].end()) flag = true;
}
signed main() {
    scanf("%lld%lld", &n, &m);
    rep(i, m) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        x--, y--;
        G[x].push_back(y);
        deg[y]++;
    }
    topsort();
    if (flag) puts("1");
    else {
        rep(i, n) printf("%lld\n", ans[i] + 1);
        puts("0");
    }
    return 0;
}
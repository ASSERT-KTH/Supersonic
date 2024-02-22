#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int N = 1e5+10, LOG = 20;
int depth[N], par[N][LOG];
vector<int> g[N];
void dfs(int v, int p = -1) {
    par[v][0] = p;
    if(p + 1)
        depth[v] = depth[p] + 1;
    for(int i = 1; i < LOG; i++)
        if(par[v][i-1] + 1)
            par[v][i] = par[par[v][i-1]][i-1];
    for(int u : g[v])
        if(u - p)
            dfs(u, v);
}
int lca(int v, int u) {
    if(depth[v] < depth[u])
        swap(v, u);
    for(int i = LOG - 1; i >= 0; i--)
        if(par[v][i] + 1 && depth[par[v][i]] >= depth[u])
            v = par[v][i];
    if(v == u)
        return v;
    for(int i = LOG - 1; i >= 0; i--)
        if(par[v][i] - par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int c;
            cin >> c;
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }
    dfs(0);
    int q;
    cin >> q;
    rep(i, q) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int B = 200;
int color[100010], par[100010], depth[100010], goUp[100010];
int top[100010], sz[100010];
bool vis[100010];
int n;
vector<vector<int>> g;
void dfs_size(int v, int p) {
    sz[v] = 1;
    for (int u : g[v]) {
        if (u == p) continue;
        dfs_size(u, v);
        sz[v] += sz[u];
    }
}

void decomp(int root) {
    dfs_size(root, -1);
    int c = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        color[v] = c;
        top[v] = root;
        for (int u : g[v]) {
            if (vis[u]) continue;
            if (2 * sz[u] > sz[root]) {
                q.push(u);
                goUp[u] = v;
            } else {
                decomp(u);
            }
        }
        c++;
    }
}

int solve(int u, int v) {
    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) swap(u, v);
        u = goUp[top[u]];
    }
    while (depth[u] > depth[v]) u = goUp[u];
    while (depth[v] > depth[u]) v = goUp[v];
    while (u != v) {
        u = goUp[u];
        v = goUp[v];
    }
    return u;
}

int main() {
    cin >> n;
    g.resize(n);
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int c;
            cin >> c;
            --c;
            g[i].push_back(c);
        }
    }
    decomp(0);
    int q;
    cin >> q;
    rep(i, q) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << solve(u, v) + 1 << endl;
    }
}
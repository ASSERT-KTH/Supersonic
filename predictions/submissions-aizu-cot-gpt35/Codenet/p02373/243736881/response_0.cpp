#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int B = 200;
const int MAXN = 100010;

int color[MAXN], par[MAXN], depth[MAXN];
int top[MAXN];
int goUp[MAXN];
int n;
vector<vector<int>> g;

void decomp(int root) {
    vector<bool> vis(n, false);
    vector<int> tord;
    queue<int> q;
    q.push(root);
    vis[root] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        tord.push_back(v);
        for (int c : g[v]) {
            if (!vis[c]) {
                q.push(c);
                vis[c] = true;
                par[c] = v;
                depth[c] = depth[v] + 1;
            }
        }
    }
    fill(vis.begin(), vis.end(), false);
    int c = 0;
    for (int u : tord) {
        if (vis[u])
            continue;
        q.push(u);
        int k = 0;
        while (!q.empty() && k < B) {
            int v = q.front();
            q.pop();
            vis[v] = true;
            color[v] = c;
            goUp[v] = par[u];
            top[v] = u;
            k++;
            for (int c : g[v]) {
                if (!vis[c])
                    q.push(c);
            }
        }
        c++;
    }
}

int solve(int u, int v) {
    while (color[u] != color[v]) {
        if (depth[top[u]] > depth[top[v]])
            u = goUp[u];
        else
            v = goUp[v];
    }
    while (u != v) {
        if (depth[u] > depth[v])
            u = par[u];
        else
            v = par[v];
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    g.reserve(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        g.push_back({});
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            g[i].push_back(c);
            par[c] = i;
        }
    }
    decomp(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << endl;
    }

    return 0;
}
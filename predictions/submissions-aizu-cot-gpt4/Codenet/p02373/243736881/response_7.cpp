#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

const int B = 200;
int color[100010], par[100010], depth[100010];
int top[100010];
int goUp[100010];
bool vis[100010];
int n;
std::vector<std::vector<int>> g;

inline void rep(int i, int n, auto&& func) {
    while(i < n) func(i++);
}

void decomp(int root) {
    rep(0, n, [&](int i){ vis[i] = false, par[i] = -1; });
    std::queue<int> q;
    q.push(root);
    std::vector<int> tord;
    tord.reserve(n);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        vis[v] = true;
        tord.emplace_back(v);
        for (int c : g[v]) {
            if (!vis[c]) {
                q.push(c);
                par[c] = v;
                depth[c] = depth[v] + 1;
            }
        }
    }
    rep(0, n, [&](int i){ vis[i] = false; });
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
        while (!q.empty())
            q.pop();
        c++;
    }
}

int solve(int u, int v) {
    while (color[u] != color[v]) {
        assert(u != -1 && v != -1);
        if (depth[top[u]] > depth[top[v]])
            u = goUp[u];
        else
            v = goUp[v];
    }
    while (u != v) {
        assert(u != -1 && v != -1);
        if (depth[u] > depth[v])
            u = par[u];
        else
            v = par[v];
    }
    return u;
}
int main() {
    std::cin >> n;
    g.assign(n, {});
    rep(0, n, [&](int i){
        int k;
        std::cin >> k;
        rep(0, k, [&](int j){
            int c;
            std::cin >> c;
            g[i].push_back(c);
            par[c] = i;
        });
    });
    decomp(0);
    int q;
    std::cin >> q;
    rep(0, q, [&](int i){
        int u, v;
        std::cin >> u >> v;
        std::cout << solve(u, v) << std::endl;
    });
}
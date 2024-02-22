#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

const int B = 200;
const int MAX_N = 100010;

struct Node {
    int color;
    int par;
    int depth;
    int top;
    int goUp;
};

int solve(const std::vector<Node>& nodes, int u, int v) {
    while (nodes[u].color != nodes[v].color) {
        if (nodes[nodes[u].top].depth > nodes[nodes[v].top].depth)
            u = nodes[u].goUp;
        else
            v = nodes[v].goUp;
    }
    while (u != v) {
        if (nodes[u].depth > nodes[v].depth)
            u = nodes[u].par;
        else
            v = nodes[v].par;
    }
    return u;
}

void decomp(const std::vector<std::vector<int>>& g, std::vector<Node>& nodes) {
    int n = g.size();
    std::vector<bool> vis(n, false);
    std::vector<int> par(n, -1);
    std::queue<int> q;
    int c = 0;
  
    for (int root = 0; root < n; root++) {
        if (vis[root])
            continue;

        q.push(root);
        int k = 0;

        while (!q.empty() && k < B) {
            int u = q.front();
            q.pop();
            vis[u] = true;
            nodes[u].color = c;
            nodes[u].goUp = nodes[u].par;

            if (k == 0)
                nodes[u].top = u;

            k++;

            for (int v : g[u]) {
                if (!vis[v]) {
                    q.push(v);
                    par[v] = u;
                    nodes[v].depth = nodes[u].depth + 1;
                }
            }
        }

        c++;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        g[i].resize(k);
        for (int j = 0; j < k; j++) {
            std::cin >> g[i][j];
        }
    }

    std::vector<Node> nodes(n);
    decomp(g, nodes);

    int q;
    std::cin >> q;

    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << solve(nodes, u, v) << '\n';
    }

    return 0;
}
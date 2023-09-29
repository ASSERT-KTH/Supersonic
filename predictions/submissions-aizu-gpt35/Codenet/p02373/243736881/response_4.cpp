#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100010;
const int BLOCK_SIZE = 200;

int color[MAXN], par[MAXN], depth[MAXN];
int top[MAXN];
int goUp[MAXN];
int n;

vector<int> g[MAXN];

void dfs(int v, int p, vector<int>& tord) {
    tord.push_back(v);
    par[v] = p;
    for (int c : g[v]) {
        if (c != p) {
            depth[c] = depth[v] + 1;
            dfs(c, v, tord);
        }
    }
}

void decomp(int root) {
    vector<int> tord;
    dfs(root, -1, tord);
    int c = 0;
    for (int i = 0; i < n; i += BLOCK_SIZE) {
        for (int j = i; j < min(n, i + BLOCK_SIZE); j++) {
            color[tord[j]] = c;
            top[tord[j]] = tord[i];
            goUp[tord[j]] = (j == i ? par[tord[i]] : tord[j - 1]);
        }
        c++;
    }
}

int solve(int u, int v) {
    while (color[u] != color[v]) {
        if (depth[top[u]] > depth[top[v]]) {
            u = goUp[u];
        } else {
            v = goUp[v];
        }
    }
    while (u != v) {
        if (depth[u] > depth[v]) {
            u = par[u];
        } else {
            v = par[v];
        }
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            g[i].push_back(c);
        }
    }
    decomp(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << "\n";
    }
    return 0;
}
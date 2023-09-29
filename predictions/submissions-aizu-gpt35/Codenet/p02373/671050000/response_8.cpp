#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(A) A.begin(), A.end()
#define PB push_back
using namespace std;
struct HeavyLight {
    vector<vector<int>> tree;
    int pathCount, n;
    vector<int> parent, in, out, path, pathSize, pathPos, pathRoot, depth;
    vector<int> jump, first, euler, idx;
    HeavyLight(vector<vector<int>> tree): tree(tree), n(tree.size()), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n), depth(n), jump(n, -1), first(n), idx(n), euler(2*n) {
            int time = 0;
            dfs(0, -1, time);
            buildPaths();
            preprocess();
        }
    void dfs(int u, int p, int &k) {
        in[u] = k++;
        euler[first[u] = k - 1] = u;
        parent[u] = p;
        for (int v: tree[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, k);
            euler[k++] = u;
        }
        out[u] = k++;
        euler[first[u + 1] = k - 1] = u;
    }
    void buildPaths() {
        int curPath = 0;
        REP(i, n) {
            if (i == 0 || pathSize[curPath] * 2 < i) {
                pathRoot[path[curPath] = i] = i;
                ++curPath;
            }
            else {
                path[curPath - 1] = i;
            }
            idx[i] = pathSize[curPath - 1]++;
            pathPos[i] = path[curPath - 1];
        }
        pathCount = curPath;
    }
    void preprocess() {
        REP(i, euler.size()) {
            if (jump[euler[i]] == -1) {
                jump[euler[i]] = i;
            }
        }
        for (int i = 2; i < jump.size(); ++i) {
            if (jump[i] == -1) {
                jump[i] = jump[i - 1];
            }
        }
    }
    bool isAncestor(int p, int ch) {
        return in[p] <= in[ch] && out[ch] <= out[p];
    }
    int lca(int a, int b) {
        int u = a, v = b;
        while (path[u] != path[v]) {
            if (depth[pathRoot[path[u]]] < depth[pathRoot[path[v]]]) {
                swap(u, v);
            }
            u = parent[pathRoot[path[u]]];
        }
        if (idx[u] > idx[v]) {
            swap(u, v);
        }
        return euler[jump[euler[idx[u]]] + jump[euler[idx[v]]]];
    }
};
int main(void) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    REP(i, n) {
        int k;
        cin >> k;
        REP(j, k) {
            int ch;
            cin >> ch;
            tree[i].PB(ch);
        }
    }
    HeavyLight hl = HeavyLight(tree);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << hl.lca(u, v) << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

template <class Key>
struct RandomizedBinarySearchTree {
    // Implementation of Randomized Binary Search Tree
    // ...
};

template <class Key>
struct PresidentRandomizedBinarySearchTree : RandomizedBinarySearchTree<Key> {
    // Implementation of President Randomized Binary Search Tree
    // ...
};

template <class T>
struct OrderedMultiSet : PresidentRandomizedBinarySearchTree<T> {
    // Implementation of Ordered MultiSet
    // ...
};

struct CentroidPathDecomposition {
    // Implementation of Centroid Path Decomposition
    // ...
};

OrderedMultiSet<int> tree(5000000);
unordered_map<OrderedMultiSet<int>::Node*, int> nodeCounts;
int N, Q, X[100000];
vector<int> g[100000];
int parent[100000];

void dfs(int idx, int par, OrderedMultiSet<int>::Node *par_set) {
    parent[idx] = par;
    tree.insert_key(par_set, X[idx]);
    nodeCounts[par_set]++;
    for (auto &to : g[idx]) {
        if (to != par) {
            dfs(to, idx, par_set);
        }
    }
}

int main() {
    scanf("%d %d", &N, &Q);
    CentroidPathDecomposition gg(N);
    vector<int> vs;
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        vs.push_back(X[i]);
    }
    for (int i = 1; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
        gg.AddEdge(x, y);
    }
    dfs(0, -1, tree.makeset());
    gg.Build();
    for (int i = 0; i < Q; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        --x, --y;
        int lca = gg.LCA(x, y);
        int ng = -1, ok = (int)vs.size() - 1;
        auto sum = [&](int v) {
            int ret = 0;
            ret += tree.upper_bound(nodes[x], vs[v]);
            ret += tree.upper_bound(nodes[y], vs[v]);
            ret -= tree.upper_bound(nodes[lca], vs[v]);
            if (lca) {
                ret -= tree.upper_bound(nodes[parent[lca]], vs[v]);
            }
            return ret;
        };
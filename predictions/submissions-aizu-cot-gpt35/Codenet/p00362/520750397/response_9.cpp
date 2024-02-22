#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;

// Data structures
vector<map<LL, LL>> graph;
vector<LL> parent;
vector<LL> depth;
vector<LL> subtreeSize;
vector<LL> weight;
vector<LL> prefixSum;

// Function to calculate prefix sum
LL calculatePrefixSum(LL index) {
    LL sum = 0;
    while (index > 0) {
        sum += prefixSum[index];
        index -= index & (-index);
    }
    return sum;
}

// Function to update prefix sum
void updatePrefixSum(LL index, LL value) {
    while (index < prefixSum.size()) {
        prefixSum[index] += value;
        index += index & (-index);
    }
}

// Function for depth-first search traversal
void dfs(LL node, LL parent, LL d) {
    depth[node] = d;
    subtreeSize[node] = 1;
    for (auto& neighbor : graph[node]) {
        LL child = neighbor.first;
        if (child == parent) continue;
        weight[child] = neighbor.second;
        dfs(child, node, d + 1);
        subtreeSize[node] += subtreeSize[child];
        if (parent == -1 || subtreeSize[child] > subtreeSize[graph[node].begin()->first]) {
            graph[node].begin()->first = child;
        }
    }
}

// Function to calculate the sum of weights in a path
LL calculateSum(LL node) {
    LL sum = 0;
    while (node != -1) {
        sum += weight[node];
        node = parent[node];
    }
    return sum;
}

int main() {
    // Read input
    LL n, k;
    cin >> n >> k;
    
    // Initialize data structures
    graph.resize(n + 1);
    parent.resize(n + 1, -1);
    depth.resize(n + 1);
    subtreeSize.resize(n + 1);
    weight.resize(n + 1);
    prefixSum.resize(n + 1, 0);
    
    // Build the graph
    for (LL i = 1; i < n; i++) {
        LL a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    
    // Perform depth-first search traversal
    dfs(1, -1, 0);
    
    // Calculate prefix sum
    for (LL i = 1; i <= n; i++) {
        updatePrefixSum(i, weight[i]);
    }
    
    // Process queries
    char s;
    while (cin >> s) {
        if (s == 'Q') {
            LL a;
            cin >> a;
            cout << calculateSum(a) << endl;
        } else {
            LL a, b;
            cin >> a >> b;
            updatePrefixSum(a, b - weight[a]);
            weight[a] = b;
        }
    }
    
    return 0;
}
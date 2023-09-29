#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

#define int long long
#define pb(x) push_back(x)
#define P pair<int, int>

using namespace std;

class TopologicalSort {
public:
    int n;
    vector<int> result, degrees;
    vector<vector<int>> graph;
    void init(int numNodes) {
        n = numNodes;
        degrees.resize(n);
        graph.resize(n);
    }
    void addEdge(int from, int to) {
        graph[from].pb(to);
        degrees[to]++;
    }
    void sort() {
        stack<int> zeroOutDegreeNodes;
        for (int i = 0; i < n; i++) 
            if (degrees[i] == 0) 
                zeroOutDegreeNodes.push(i);
                
        while (!zeroOutDegreeNodes.empty()) {
            int v = zeroOutDegreeNodes.top();
            zeroOutDegreeNodes.pop();
            result.pb(v);
            for (const auto& node : graph[v]) 
                if (--degrees[node] == 0) 
                    zeroOutDegreeNodes.push(node);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    TopologicalSort sorter;
    sorter.init(n);

    unordered_map<P, int> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        sorter.addEdge(x, y);
        edges[P(x, y)] = 1;
    }

    sorter.sort();
    vector<int>& result = sorter.result;
    
    for (const auto& node : result) 
        cout << node + 1 << "\n";

    int isDAG = 1;
    for (int i = 0; i < n - 1; i++)
        if (edges[P(result[i], result[i + 1])] == 0)
            isDAG = 0;

    cout << (isDAG == 1 ? 0 : 1) << "\n";

    return 0;
}
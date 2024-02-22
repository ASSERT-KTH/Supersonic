#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int parent;
    int depth;
    int color;
    int goUp;
    int top;
};

void decompose(const vector<vector<int>>& graph, vector<Node>& nodes, int root, int& colorCount) {
    nodes[root].depth = 0;
    nodes[root].color = colorCount;
    nodes[root].top = root;
    
    vector<int> stack;
    stack.push_back(root);
    
    while (!stack.empty()) {
        int node = stack.back();
        stack.pop_back();
        
        for (int child : graph[node]) {
            if (nodes[child].depth == -1) {
                nodes[child].parent = node;
                nodes[child].depth = nodes[node].depth + 1;
                
                stack.push_back(child);
            }
        }
    }
    
    for (int node : stack) {
        int current = node;
        int k = 0;
        
        while (current != -1 && k < 200) {
            nodes[current].color = colorCount;
            nodes[current].goUp = nodes[node].parent;
            nodes[current].top = node;
            
            current = nodes[current].parent;
            k++;
        }
        
        colorCount++;
    }
}

int solve(const vector<Node>& nodes, int u, int v) {
    while (nodes[u].color != nodes[v].color) {
        if (nodes[nodes[u].top].depth > nodes[nodes[v].top].depth)
            u = nodes[u].goUp;
        else
            v = nodes[v].goUp;
    }
    
    while (u != v) {
        if (nodes[u].depth > nodes[v].depth)
            u = nodes[u].parent;
        else
            v = nodes[v].parent;
    }
    
    return u;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n);
    vector<Node> nodes(n);
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            
            graph[i].push_back(c);
            nodes[c].parent = i;
        }
    }
    
    int colorCount = 0;
    decompose(graph, nodes, 0, colorCount);
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        
        cout << solve(nodes, u, v) << endl;
    }
    
    return 0;
}
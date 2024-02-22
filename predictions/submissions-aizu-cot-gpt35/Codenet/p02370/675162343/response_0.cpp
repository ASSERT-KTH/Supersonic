#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

typedef vector<unordered_set<int>> Adj_list;

void topological_sort(Adj_list& G, vector<int>& topological_order) {
    const int V = G.size();
    vector<int> inorder(V, 0);
    for (int i = 0; i < V; i++) {
        for (int tgt : G[i]) {
            inorder[tgt]++;
        }
    }
    
    stack<int> S;
    for (int i = 0; i < V; i++) {
        if (inorder[i] == 0) {
            S.push(i);
        }
    }
    
    while (!S.empty()) {
        int v = S.top();
        S.pop();
        topological_order.push_back(v);
        for (int tgt : G[v]) {
            inorder[tgt]--;
            if (inorder[tgt] == 0) {
                S.push(tgt);
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    Adj_list G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].insert(t);
    }
    
    vector<int> topological_order;
    topological_sort(G, topological_order);
    
    for (int v : topological_order) {
        cout << v << endl;
    }
    
    return 0;
}
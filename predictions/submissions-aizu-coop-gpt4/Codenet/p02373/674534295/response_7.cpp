#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // adjacency list representation of the graph
vector<vector<int>> up; // binary lifting table
vector<int> depth; // depth of each node from root

void dfs(int node, int parent){
    up[node][0] = parent;
    for(int i=1;i<20;++i){
        if(up[node][i-1] != -1) up[node][i] = up[up[node][i-1]][i-1];
    }

    for(int child : adj[node]){
        if(child == parent) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0;i<20;++i){
        if((diff>>i)&1) u = up[u][i];
    }
    if(u == v) return u;

    for(int i=19;i>=0;--i){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n; cin >> n;
    adj.resize(n);
    up.assign(n, vector<int>(20, -1));
    depth.resize(n);

    for(int i=0;i<n;++i){
        int k; cin >> k;
        for(int j=0;j<k;++j){
            int v; cin >> v;
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
    }

    dfs(0, -1); // assuming 0 as root

    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}
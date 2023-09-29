#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> adj[100100];
bool visited[100100];
int dfs(int src, int prev, int &maxi, int &cnt) {
    visited[src] = true;
    for(auto &p : adj[src]) {
        int node = p.first;
        int value = p.second;
        if(node == prev) continue;
        if(maxi == value) cnt++;
        else if(maxi < value) {
            maxi = value;
            cnt = 1;
        }
        dfs(node, src, maxi, cnt);
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n, n) {
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for(int i = 0, u, v, w; i < n; i++) {
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int maxi = -1, cnt = 0;
                ans = (ans * dfs(i, -1, maxi, cnt)) % 10007;
            }
        }
        cout << ans << '\n';
    }
}
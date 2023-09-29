#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[105];
int n, d[105];
void bfs(int s) {
    fill(d, d + n, -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        while (k--) {
            int v;
            cin >> v;
            adj[u - 1].push_back(v - 1);
        }
    }
    bfs(0);
    for (int i = 0; i < n; i++)
        cout << i + 1 << ' ' << d[i] << endl;
    return 0;
}
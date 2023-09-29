#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 105;
vector<int> adj[MAX];
int n, d[MAX];

void bfs() {
    queue<int> q;
    q.push(0);
    d[0] = 0;
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
    for (int i = 0; i < n; i++)
        d[i] = -1;
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            adj[u-1].push_back(v-1);
        }
    }
    bfs();
    for (int i = 0; i < n; i++)
        cout << i+1 << ' ' << d[i] << endl;
    return 0;
}
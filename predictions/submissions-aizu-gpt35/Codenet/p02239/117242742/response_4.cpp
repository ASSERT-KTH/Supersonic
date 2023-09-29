#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 105;
vector<int> adj[MAXN];
bool v[MAXN];
int d[MAXN];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    v[s] = true;
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : adj[u]) {
            if (!v[i]) {
                v[i] = true;
                d[i] = d[u] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int n;
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
        cout << i + 1 << ' ' << d[i] << '\n';
    return 0;
}
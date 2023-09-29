#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<pair<int, int>> adj[MAXN], adjInv[MAXN];
int dist[MAXN], deg[MAXN], visited[MAXN], decreased[MAXN];

void bfs(int source) {
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto edge : adj[v]) {
            int u = edge.first;
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    fill(dist + 1, dist + n + 1, INT_MAX);
    bfs(1);

    for (int i = 1; i <= n; i++) {
        for (auto edge : adj[i]) {
            int j = edge.first, idx = edge.second;
            if (dist[i] < dist[j]) {
                adjInv[j].push_back({i, idx});
                deg[i]++;
            }
        }
    }

    int cnt = 0;
    while (q--) {
        int idx;
        cin >> idx;
        int a = adj[1][idx - 1].first, b = adj[1][idx - 1].second;
        if (dist[a] > dist[b]) swap(a, b);
        if (!visited[idx] && !decreased[b]) {
            visited[idx] = 1;
            deg[b]--;
            if (!deg[b]) {
                decreased[b] = 1;
                cnt++;
                queue<int> q;
                q.push(b);
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (auto edge : adjInv[v]) {
                        int u = edge.first, idx = edge.second;
                        if (!visited[idx]) {
                            visited[idx] = 1;
                            deg[u]--;
                            if (!deg[u] && !decreased[u]) {
                                decreased[u] = 1;
                                cnt++;
                                q.push(u);
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
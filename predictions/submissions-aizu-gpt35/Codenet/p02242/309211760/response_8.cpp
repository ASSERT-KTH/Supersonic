#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);
vector<pair<int, int>> adj[MAX];
int n, dist[MAX];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        dist[i] = INFTY;
    }
    dist[0] = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        if (dist[u] < p.first) {
            continue;
        }
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (dist[v] > dist[u] + adj[u][i].second) {
                dist[v] = dist[u] + adj[u][i].second;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << " " << (dist[i] == INFTY ? -1 : dist[i]) << endl;
    }
}

int main() {
    cin >> n;
    int k, c, u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            adj[u].push_back(make_pair(v, c));
        }
    }
    dijkstra();
    return 0;
}
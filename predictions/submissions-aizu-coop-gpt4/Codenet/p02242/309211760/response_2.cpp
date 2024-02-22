#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

static const int INFTY = (1 << 21);

void dijkstra(vector<vector<pair<int, int>>>& adj, int n) {
    vector<pair<int, int>> state(n, {INFTY, 0}); // distance and color
    state[0].first = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (state[u].second == 2)
            continue;

        state[u].second = 2;

        for (auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (state[v].first > state[u].first + w) {
                state[v].first = state[u].first + w;
                if (state[v].second != 1) {
                    state[v].second = 1;
                    pq.push({state[v].first, v});
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << i << " " << (state[i].first == INFTY ? -1 : state[i].first) << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    int k, c, u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            adj[u].push_back({v, c});
        }
    }
    dijkstra(adj, n);
    return 0;
}
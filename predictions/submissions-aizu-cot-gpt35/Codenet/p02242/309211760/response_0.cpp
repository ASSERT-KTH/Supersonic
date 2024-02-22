#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int n, vector<vector<pii>>& adjList) {
    vector<int> distance(n, INT_MAX);
    distance[0] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << (distance[i] == INT_MAX ? -1 : distance[i]) << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<pii>> adjList(n);

    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;

        for (int j = 0; j < k; j++) {
            int v, c;
            cin >> v >> c;
            adjList[u].push_back({v, c});
        }
    }

    dijkstra(n, adjList);

    return 0;
}
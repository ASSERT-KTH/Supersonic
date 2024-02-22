#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1<<21);

vector<pair<int, int>> adj[MAX]; // adjacency list
int n;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<int> d(n, INFTY);
    d[0] = 0;
    PQ.push(make_pair(0, 0));

    while (!PQ.empty()) {
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;
        int d_u = f.first;
        if (d[u] < d_u) continue;

        for (auto &j : adj[u]) {
            int v = j.first;
            int cost = j.second;
            if (d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                PQ.push(make_pair(d[v], v));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
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
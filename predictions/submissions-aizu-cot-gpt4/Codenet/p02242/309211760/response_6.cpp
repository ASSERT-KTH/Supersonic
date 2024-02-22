#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INFTY = (1 << 21);
const int MAX = 100;
typedef pair<int, int> P;

vector<P> adj[MAX];
int n;

void dijkstra() {
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> d(n, INFTY);
    d[0] = 0;
    pq.push(P(0, 0));
    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        int u = p.second;
        if (d[u] < p.first) continue;
        for (auto &x : adj[u]) {
            int v = x.first, dist = x.second;
            if (d[v] > d[u] + dist) {
                d[v] = d[u] + dist;
                pq.push(P(d[v], v));
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
            adj[u].push_back(P(v, c));
        }
    }
    dijkstra();
    return 0;
}
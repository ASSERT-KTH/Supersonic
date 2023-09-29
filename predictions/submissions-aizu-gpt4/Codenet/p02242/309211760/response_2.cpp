#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P; // pair of shortest distance and vertex number
static const int MAX = 100;
static const int INFTY = (1 << 21);

vector<P> adj[MAX]; // adjacency list

void dijkstra() {
    priority_queue<P, vector<P>, greater<P>> Q; // min heap 
    vector<int> d(MAX, INFTY); // initial distances are INFTY
    d[0] = 0; // distance of start vertex from itself is 0
    Q.push(P(0, 0)); 

    while (!Q.empty()) {
        P p = Q.top(); Q.pop();
        int u = p.second;
        if (d[u] < p.first) continue;
        for (auto &p : adj[u]) {
            if (d[p.second] > d[u] + p.first) {
                d[p.second] = d[u] + p.first;
                Q.push(P(d[p.second], p.second));
            }
        }
    }

    for (int i = 0; i < MAX; ++i) {
        if(d[i] == INFTY) {
            cout << i << " " << -1 << endl;
        } else {
            cout << i << " " << d[i] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, k, v, c;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            cin >> v >> c;
            adj[u].push_back(P(c, v));
        }
    }
    dijkstra();
    return 0;
}
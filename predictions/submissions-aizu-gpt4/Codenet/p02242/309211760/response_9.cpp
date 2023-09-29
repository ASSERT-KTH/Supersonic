#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INFTY = (1 << 21);

struct Edge {
    int to, cost;
};

typedef pair<int, int> P; 

vector<Edge> G[100];
int d[100];

void dijkstra() {
    priority_queue<P, vector<P>, greater<P>> Q;
    fill(d, d + 100, INFTY);
    d[0] = 0;
    Q.push(P(0, 0));
    while (!Q.empty()) {
        P p = Q.top(); Q.pop();
        int u = p.second;
        if (d[u] < p.first) continue;
        for (auto e : G[u]) {
            if (d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                Q.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int n, k, c, u, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            G[u].push_back((Edge){v, c});
        }
    }
    dijkstra();
    for (int i = 0; i < n; i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#define INFTY (1<<21)
#define MAX 100
using namespace std;

struct edge {
    int to, cost;
};

typedef pair<int, int> P;
vector<edge> G[MAX];
int n, d[MAX];

void dijkstra() {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + n, INFTY);
    d[0] = 0;
    que.push(P(0, 0));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v, c;
            cin >> v >> c;
            G[u].push_back((edge){v, c});
        }
    }
    dijkstra();
    return 0;
}
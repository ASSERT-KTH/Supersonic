#include <iostream>
#include <queue>
#include <vector>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);
vector<pair<int, int>> adjList[MAX];
int n, d[MAX];
void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        d[i] = INFTY;
    }
    d[0] = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        pair<int, int> f = pq.top();
        pq.pop();
        int u = f.second;
        if (d[u] < f.first) {
            continue;
        }
        for (int j = 0; j < adjList[u].size(); j++) {
            int v = adjList[u][j].first;
            if (d[v] > d[u] + adjList[u][j].second) {
                d[v] = d[u] + adjList[u][j].second;
                pq.push(make_pair(d[v], v));
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
            adjList[u].push_back(make_pair(v, c));
        }
    }
    dijkstra();
    return 0;
}
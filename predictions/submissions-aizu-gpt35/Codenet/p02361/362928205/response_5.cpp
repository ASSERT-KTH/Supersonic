#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9;
int v, e, r;
struct Edge {
    int to, cost;
    Edge(int to = 0, int cost = 0): to(to), cost(cost) {}
};
vector<Edge> G[N];
int d[N];
void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    fill(d, d + v, INF);
    d[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int nv = p.second;
        if (p.first > d[nv])
            continue;
        for (auto &e: G[nv]) {
            if (d[nv] + e.cost < d[e.to]) {
                d[e.to] = d[nv] + e.cost;
                q.push(make_pair(d[e.to], e.to));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v >> e >> r;
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }
    dijkstra(r);
    for (int i = 0; i < v; i++) {
        if (d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }
    return 0;
}
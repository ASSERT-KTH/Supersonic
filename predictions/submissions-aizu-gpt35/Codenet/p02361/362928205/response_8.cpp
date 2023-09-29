#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
struct edge {
    int to, cost;
};
vector<edge> G[100000];
int v, e, r;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e >> r;
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(edge{t, d});
    }
    vector<int> d(v, INF);
    d[r] = 0;
    q.push({0, r});
    while (!q.empty()) {
        auto [p, nv] = q.top();
        q.pop();
        if (p > d[nv]) continue;
        for (auto& g : G[nv]) {
            if (d[nv] + g.cost < d[g.to]) {
                d[g.to] = d[nv] + g.cost;
                q.push({d[g.to], g.to});
            }
        }
    }
    for (int i = 0; i < v; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
    return 0;
}
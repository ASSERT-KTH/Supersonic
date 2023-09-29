#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct edge {
    int to, cap, cost, rev;
    edge(int a, int b, int c, int d) : to(a), cap(b), cost(c), rev(d) {}
};
vector<edge> G[12005];
int h[12005], dist[12005];
int prevv[12005], preve[12005];
void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
}
int min_cost_flow(int s, int t, int f) {
    int res = 0;
    fill(h, h + 12005, 0);
    while (f > 0) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        fill(dist, dist + 12005, INF);
        dist[s] = 0;
        q.push({0, s});
        while (!q.empty()) {
            pair<int, int> p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    q.push({dist[e.to], e.to});
                }
            }
        }
        if (dist[t] == INF) return -1;
        for (int v = 0; v < 12005; v++) h[v] += dist[v];
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}
struct train {
    int t1, t2, cost;
};
int main() {
    int n;
    while (scanf("%d", &n), n) {
        vector<train> T[101];
        for (int i = 0; i < n - 1; i++) {
            int m;
            scanf("%d", &m);
            T[i].resize(m);
            for (int j = 0; j < m; j++)
                scanf("%d%d%d", &T[i][j].t1, &T[i][j].t2, &T[i][j].cost);
        }
        int n_class;
        scanf("%d", &n_class);
        int V = 0;
        map<int, int> f[101][2];
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < T[i].size(); j++) {
                int t1 = T[i][j].t1, t2 = T[i][j].t2;
                if (f[i][0].count(t1) == 0) f[i][0][t1] = V++;
                if (f[i + 1][0].count(t2) == 0) f[i + 1][0][t2] = V++;
                if (f[i + 1][1].count(t2) == 0) f[i + 1][1][t2] = V++;
            }
        int s = V++, t = V++;
        for (int i = 0; i < V; i++) G[i].clear();
        add_edge(s, f[0][0].begin()->second, n_class, 0);
        add_edge(f[n - 1][0].rbegin()->second, t, n_class, 0);
        for (int i = 0; i < n; i++) {
            for (auto it = f[i][0].begin(); it != f[i][0].end(); it++) {
                auto jt = next(it, 1);
                if (jt != f[i][0].end()) {
                    add_edge(it->second, jt->second, n_class, 0);
                }
            }
            for (auto it = f[i][1].begin(); it != f[i][1].end(); it++) {
                int t = it->first;
                add_edge(it->second, f[i][0][t], 1, 0);
            }
        }
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < T[i].size(); j++)
                add_edge(f[i][0][T[i][j].t1], f[i + 1][1][T[i][j].t2], 1, T[i][j].cost);
        printf("%d\n", min_cost_flow(s, t, n_class));
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to, id;
};

int n, m, q, a[210000], b[210000], c, dist[110000], T[110000], cnt;
vector<Edge> adj[110000], y[110000];
queue<int> Q;
bool used[210000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        adj[a[i]].push_back({b[i], i});
        adj[b[i]].push_back({a[i], i});
    }
    fill(dist, dist + n + 1, 999999);
    dist[1] = 0;
    Q.push(1);
    while (!Q.empty()) {
        int a1 = Q.front();
        Q.pop();
        for (Edge &e : adj[a1]) {
            if (dist[e.to] > dist[a1] + 1) {
                dist[e.to] = dist[a1] + 1;
                Q.push(e.to);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (Edge &e : adj[i]) {
            if (dist[i] < dist[e.to]) {
                y[i].push_back({e.to, e.id});
                T[e.to]++;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> c;
        c--;
        queue<Edge> Q1;
        int ss = -1;
        if (dist[a[c]] < dist[b[c]])
            ss = b[c];
        if (dist[a[c]] > dist[b[c]])
            ss = a[c];
        if (ss >= 1 && T[ss] == 0 && !used[c]) {
            Q1.push({ss, c});
            while (!Q1.empty()) {
                int to = Q1.front().to, id = Q1.front().id;
                Q1.pop();
                if (T[to] != 0 || used[id])
                    continue;
                T[to]--;
                used[id] = true;
                if (T[to] != 0)
                    continue;
                cnt++;
                T[to] = 1;
                for (Edge &e : y[to]) {
                    if (T[e.to] == 0)
                        Q1.push(e);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;
const int MAXN = 6000;

vector<int> g[MAXN];
int c[MAXN];
int r[MAXN];
int d[MAXN];
vector<int> pass[MAXN];
int n, k;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    d[v] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int dijkstra(int s, int t) {
    fill(d, d + n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;
        for (int v : pass[u]) {
            if (d[v] > d[u] + c[u]) {
                d[v] = d[u] + c[u];
                pq.push({d[v], v});
            }
        }
    }
    return d[t];
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> r[i];
    }
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        bfs(i);
        for (int j = 0; j < n; ++j) {
            if (d[j] <= r[i]) {
                pass[i].push_back(j);
            }
        }
    }
    cout << dijkstra(0, n - 1) << "\n";
    return 0;
}
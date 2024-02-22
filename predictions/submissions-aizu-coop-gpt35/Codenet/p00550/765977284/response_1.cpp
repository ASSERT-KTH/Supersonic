#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
const int MAX_M = 200000;

int n, m, q;
vector<int> adj[MAX_N];
int u[MAX_M], v[MAX_M], r[MAX_M], ans[MAX_M], d[MAX_N], cnt = 1;
bitset<MAX_N> b, ok;

void bfs(int u, int t) {
    queue<int> que;
    que.push(u);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (int v : adj[p]) {
            if (t) {
                if (d[v] > d[p] && !ok[v]) {
                    ok[v] = true;
                    cnt++;
                    que.push(v);
                }
            } else if (d[v] == -1) {
                d[v] = d[p] + 1;
                que.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    fill(d, d + n, -1);
    d[0] = 0;
    bfs(0, 0);

    for (int i = 0; i < m; i++) {
        if (d[u[i]] > d[v[i]])
            swap(u[i], v[i]);
    }

    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < q; i++) {
        cin >> r[i];
        r[i]--;
        b[r[i]] = true;
    }

    ok[0] = true;
    for (int i = 0; i < m; i++) {
        if (!b[i]) {
            if (d[v[i]] - d[u[i]] == 1) {
                adj[u[i]].push_back(v[i]);
            }
        }
    }

    bfs(0, 1);

    for (int i = q - 1; i >= 0; i--) {
        ans[i] = n - cnt;
        if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
            adj[u[r[i]]].push_back(v[r[i]]);
            if (ok[u[r[i]]]) {
                cnt++;
                ok[v[r[i]]] = true;
                bfs(v[r[i]], 1);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1e5+7;
vector<int> E[MAX];
int u[MAX*2], v[MAX*2], r[MAX*2], ans[MAX*2], d[MAX], cnt = 1;
bool b[MAX*2], ok[MAX];
queue<int> que;

void bfs(int u, bool t) {
    que.push(u);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (int v : E[p]) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        E[u[i]].push_back(v[i]);
        E[v[i]].push_back(u[i]);
    }
    memset(d, -1, sizeof(d));
    d[0] = 0;
    bfs(0, false);
    for (int i = 0; i < m; ++i) {
        if (d[u[i]] > d[v[i]])
            swap(u[i], v[i]);
    }
    for (int i = 0; i < n; ++i) E[i].clear();
    for (int i = 0; i < q; ++i) {
        cin >> r[i];
        r[i]--;
        b[r[i]] = true;
    }
    ok[0] = true;
    for (int i = 0; i < m; ++i) {
        if (!b[i]) {
            if (d[v[i]] - d[u[i]] == 1) {
                E[u[i]].emplace_back(v[i]);
            }
        }
    }
    bfs(0, true);
    for (int i = q - 1; i >= 0; --i) {
        ans[i] = n - cnt;
        if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
            E[u[r[i]]].emplace_back(v[r[i]]);
            if (ok[u[r[i]]]) {
                cnt++;
                ok[v[r[i]]] = true;
                bfs(v[r[i]], true);
            }
        }
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << "\n";
}
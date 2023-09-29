#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 2e5 + 5, Q = 2e5 + 5;
int n, m, q, u[M], v[M], d[N], ans[Q];
bool b[M], ok[N];
vector<int> E[N];
inline int read() {
    int x = 0, k = getchar();
    while (k < '0' || k > '9') k = getchar();
    while (k >= '0' && k <= '9') x = x * 10 + k - '0', k = getchar();
    return x;
}
void bfs(int s) {
    memset(d, 0x3f, sizeof(d)), memset(ok, false, sizeof(ok));
    queue<int> q;
    d[s] = 0, q.push(s), ok[s] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < E[x].size(); i++) {
            int y = E[x][i];
            if (d[y] == 0x3f3f3f3f) {
                d[y] = d[x] + 1;
                q.push(y);
                ok[y] = true;
            }
        }
    }
}
int main() {
    n = read(), m = read(), q = read();
    for (int i = 1; i <= m; i++) {
        u[i] = read(), v[i] = read();
        E[u[i]].push_back(v[i]), E[v[i]].push_back(u[i]);
    }
    bfs(1);
    for (int i = 1; i <= m; i++)
        if (d[u[i]] + 1 == d[v[i]]) b[i] = true;
    for (int i = 1; i <= q; i++) {
        int x = read();
        b[x] = true;
    }
    bfs(1);
    for (int i = q; i >= 1; i--) {
        ans[i] = n - E[1].size();
        if (b[i]) continue;
        if (d[u[i]] + 1 == d[v[i]]) E[v[i]].push_back(u[i]);
    }
    for (int i = 2; i <= n; i++)
        if (!ok[i]) ans[1]++;
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 200005;
int n, m;
int cnt = 0;
int head[MAXN], to[MAXN], nxt[MAXN], indeg[MAXN], vis[MAXN], topo[MAXN];

void add_edge(int u, int v) {
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}

void dfs(int u) {
    vis[u] = 1;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (!vis[v]) dfs(v);
    }
    topo[++topo[0]] = u;
}

void topsort() {
    for (int i = 1; i <= n; i++) {
        if (!indeg[i] && !vis[i]) {
            dfs(i);
        }
    }
    if (topo[0] < n) {
        printf("1\n");
        return;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = head[topo[i]]; j; j = nxt[j]) {
            int v = to[j];
            indeg[v]--;
            if (indeg[v] == 0) {
                dfs(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (topo[i] != i) {
            printf("1\n");
            return;
        }
    }
    printf("0\n");
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%lld %lld", &u, &v);
        add_edge(u, v);
        indeg[v]++;
    }
    topsort();
    return 0;
}
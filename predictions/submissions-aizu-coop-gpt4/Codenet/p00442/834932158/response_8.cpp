#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 7;
vector<int> G[MAX_N];
vector<int> ans;
int deg[MAX_N];
bool edge[MAX_N][MAX_N];

void add_edge(int from, int to) {
    G[from].push_back(to);
    deg[to]++;
}

void tsort(int n) {
    queue<int> q;
    for(int i = 0; i < n; i++) if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for(int i = 0; i < G[v].size(); i++) if (--deg[G[v][i]] == 0) q.push(G[v][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        add_edge(x, y);
        edge[x][y] = 1;
    }

    tsort(n);

    for(int i = 0; i < n; i++) cout << ans[i] + 1 << '\n';

    int res = 1;
    for(int i = 0; i < n - 1; i++) {
        if (edge[ans[i]][ans[i + 1]] == 0)
            res = 0;
    }
    cout << (res == 1 ? 0 : 1) << '\n';

    return 0;
}
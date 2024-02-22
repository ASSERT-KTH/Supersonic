#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 999999999

vector<vector<int>> pass;
vector<int> c, r, d;
vector<bool> used, visited;

void dfs(int v, int u, int f, int end) {
    if(visited[u])
        return;
    visited[u] = true;
    d[u] = min(d[u], d[v] + c[v]);
    if(f >= end)
        return;
    for(int i = 0; i < pass[u].size(); i++) {
        dfs(v, pass[u][i], f + 1, end);
    }
}

int dijk(int s, int g) {
    fill(d.begin(), d.end(), INF);
    fill(used.begin(), used.end(), false);
    d[s] = 0;
    while (1) {
        int v = -1;
        for(int u = 0; u < d.size(); u++) {
            if (!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        }
        if (v == -1)
            break;
        used[v] = true;
        fill(visited.begin(), visited.end(), false);
        for(int i = 0; i < pass[v].size(); i++) {
            dfs(v, pass[v][i], 1, r[v]);
        }
    }
    return d[g];
}

int main() {
    int n, k;
    cin >> n >> k;
    pass.resize(n);
    c.resize(n);
    r.resize(n);
    d.resize(n);
    used.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i++)
        cin >> c[i] >> r[i];
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pass[a].push_back(b);
        pass[b].push_back(a);
    }
    cout << dijk(0, n - 1) << endl;
}
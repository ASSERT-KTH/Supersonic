#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 999999999;
const int MAXN = 6000;

vector<int> pass[MAXN];
int n, k;
int c[MAXN];
int r[MAXN];
int d[MAXN];
bool used[MAXN];

void dfs(int v, int u, int f, int end, bool visited[]) {
    if (visited[u]) return;
    visited[u] = true;
    d[u] = min(d[u], d[v] + c[v]);
    if (f >= end) return;
    for (int i = 0; i < pass[u].size(); i++) {
        dfs(v, pass[u][i], f + 1, end, visited);
    }
}

int dijk(int s, int g) {
    memset(d, INF, sizeof(d));
    memset(used, false, sizeof(used));
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (used[v]) continue;
        used[v] = true;
        for (int i = 0; i < pass[v].size(); i++) {
            bool visited[MAXN] = {};
            dfs(v, pass[v][i], 1, r[v], visited);
        }
    }
    return d[g];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> c[i] >> r[i];
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pass[a].push_back(b);
        pass[b].push_back(a);
    }
    cout << dijk(0, n - 1) << endl;
    return 0;
}
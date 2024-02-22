#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int maxN = 6000;
vector<int> pass[maxN];
int n, k, c[maxN], r[maxN], d[maxN];
bool used[maxN], visited[maxN];

void dfs(int v, int u, int f, int end) {
    if (visited[u])
        return;
    visited[u] = true;
    d[u] = min(d[u], d[v] + c[v]);
    if (f >= end)
        return;
    for(auto it = pass[u].begin(); it != pass[u].end(); it++) {
        dfs(v, *it, f + 1, end);
    }
}

void dijk(int s, int g) {
    fill_n(d, maxN, INT_MAX);
    fill_n(used, maxN, false);
    d[s] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if(used[v]) continue;
        used[v] = true;
        fill_n(visited, maxN, false);
        for(auto it = pass[v].begin(); it != pass[v].end(); it++) {
            dfs(v, *it, 1, r[v]);
        }
        for(int i = 0; i < n; i++) {
            if(!used[i])
                pq.push(make_pair(d[i], i));
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> c[i] >> r[i];
    }
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pass[a].push_back(b);
        pass[b].push_back(a);
    }
    dijk(0, n - 1);
    cout << d[n - 1] << endl;
    return 0;
}
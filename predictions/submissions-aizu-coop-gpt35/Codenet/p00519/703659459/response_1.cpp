#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <limits>

using namespace std;

constexpr int N = 6000;
constexpr int INF = numeric_limits<int>::max();

vector<vector<int>> pass(N);
vector<int> c(N);
vector<int> r(N);
vector<int> d(N);
bitset<N> used;

void dfs(int u, int f, int end, bitset<N>& visited) {
    if (visited[u])
        return;
    visited[u] = true;
    d[u] = min(d[u], d[u] + c[u]);
    if (f >= end)
        return;
    for (const auto& v : pass[u]) {
        dfs(v, f + 1, end, visited);
    }
}

int dijk(int s, int g) {
    fill(d.begin(), d.end(), INF);
    used.reset();
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (used[v])
            continue;
        used[v] = true;
        bitset<N> visited;
        dfs(v, 1, r[v], visited);
        for (const auto& u : pass[v]) {
            if (!used[u]) {
                pq.emplace(d[u], u);
            }
        }
    }
    return d[g];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> r[i];
    }
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
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, s, t, u, v;
    cin >> N >> M >> s >> t;
    s--; t--;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> d1(N, INF), d2(N, INF);
    d1[s] = 0; d2[t] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int& neighbor : G[node]) {
            if (d1[neighbor] == INF) {
                d1[neighbor] = d1[node] + 1;
                que.push(neighbor);
            }
        }
    }
    que.push(t);
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int& neighbor : G[node]) {
            if (d2[neighbor] == INF) {
                d2[neighbor] = d2[node] + 1;
                que.push(neighbor);
            }
        }
    }
    int shortest = d1[t];
    vector<int> r1(shortest, 0), r2(shortest, 0);
    for (int i = 0; i < N; i++) {
        if (d1[i] < shortest) r1[d1[i]]++;
        if (d2[i] < shortest) r2[d2[i]]++;
    }
    long long ret = 0;
    for (int i = 0; i < shortest - 1; i++) {
        ret += (long long) r1[i] * r2[shortest - i - 2];
    }
    cout << ret << "\n";
    return 0;
}
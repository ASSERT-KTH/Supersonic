#include <iostream>
#include <queue>
#include <vector>
#pragma warning(disable : 4996)
#define INF (1 << 23)
using namespace std;

int main() {
    int N, M, s, t, u, v;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &s);
    s--;
    scanf("%d", &t);
    t--;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        scanf("%d", &u);
        scanf("%d", &v);
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }
    vector<int> d1(N, INF), d2(N, INF), r1(N, 0), r2(N, 0);
    d1[s] = 0; d2[t] = 0;
    queue<int> q1, q2;
    q1.push(s); q2.push(t);
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            int node = q1.front(); q1.pop();
            for (int i = 0; i < G[node].size(); i++) {
                if (d1[G[node][i]] == INF) {
                    d1[G[node][i]] = d1[node] + 1;
                    q1.push(G[node][i]);
                }
            }
        }
        if (!q2.empty()) {
            int node = q2.front(); q2.pop();
            for (int i = 0; i < G[node].size(); i++) {
                if (d2[G[node][i]] == INF) {
                    d2[G[node][i]] = d2[node] + 1;
                    q2.push(G[node][i]);
                }
            }
        }
    }
    int shortest = d1[t];
    for (int i = 0; i < N; i++) {
        if (d1[i] + d2[i] == shortest) {
            r1[d1[i]]++;
            r2[d2[i]]++;
        }
    }
    long long ret = 0;
    for (int i = 0; i < shortest - 1; i++) {
        ret += 1LL * r1[i] * r2[shortest - i - 2];
    }
    printf("%lld\n", ret);
    return 0;
}
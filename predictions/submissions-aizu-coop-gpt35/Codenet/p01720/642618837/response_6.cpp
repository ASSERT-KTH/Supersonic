#include <iostream>
#include <vector>
#include <queue>

#define INF (1 << 23)

int main() {
    std::ios::sync_with_stdio(false);

    int N, M, s, t, u, v;
    std::cin >> N >> M >> s >> t;
    s--;
    t--;

    std::vector<std::vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }

    std::vector<int> d(N, INF);
    d[s] = 0;
    d[t] = 0;

    std::queue<int> que;
    que.push(s);
    que.push(t);

    while (!que.empty()) {
        int node = que.front();
        que.pop();

        for (int neighbor : G[node]) {
            if (d[neighbor] == INF) {
                d[neighbor] = d[node] + 1;
                que.push(neighbor);
            }
        }
    }

    int shortest = d[t];
    std::vector<int> r1(shortest - 1, 0);
    std::vector<int> r2(shortest - 1, 0);

    for (int i = 0; i < N; i++) {
        if (d[i] < shortest - 1) {
            r1[d[i]]++;
            r2[d[i]]++;
        }
    }

    long long ret = 0;
    for (int i = 0; i < shortest - 1; i++) {
        ret += 1LL * r1[i] * r2[shortest - i - 2];
    }

    std::cout << ret << "\n";
    return 0;
}
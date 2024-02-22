#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

#define INF (1 << 23)

int main() {
    int N, M, s, t, u, v;
    std::cin >> N;
    std::cin >> M;
    std::cin >> s;
    s--;
    std::cin >> t;
    t--;

    std::vector<std::vector<int>> G(N);
    G.reserve(M);

    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }

    std::vector<int> d1(N, INF);
    d1[s] = 0;
    std::vector<int> d2(N, INF);
    d2[t] = 0;

    std::deque<int> que;
    que.push_back(s);

    while (!que.empty()) {
        int node = que.front();
        que.pop_front();

        for (int neighbor : G[node]) {
            if (d1[neighbor] == INF) {
                d1[neighbor] = d1[node] + 1;
                que.push_back(neighbor);
            }
        }
    }

    que.push_back(t);

    while (!que.empty()) {
        int node = que.front();
        que.pop_front();

        for (int neighbor : G[node]) {
            if (d2[neighbor] == INF) {
                d2[neighbor] = d2[node] + 1;
                que.push_back(neighbor);
            }
        }
    }

    int shortest = d1[t];
    std::vector<int> r1(shortest - 1, 0);
    std::vector<int> r2(shortest - 1, 0);

    for (int i = 0; i < N; i++) {
        if (d1[i] < shortest - 1) {
            r1[d1[i]]++;
        }
        if (d2[i] < shortest - 1) {
            r2[d2[i]]++;
        }
    }

    long long ret = std::accumulate(r1.begin(), r1.end(), 0LL,
        [&r2, shortest](long long sum, int val) {
            return sum + val * r2[shortest - val - 2];
        });

    std::cout << ret << "\n";
    return 0;
}
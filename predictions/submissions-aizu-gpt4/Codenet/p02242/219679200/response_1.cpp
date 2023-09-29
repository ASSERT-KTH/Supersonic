#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using uint = unsigned int;
using pii = std::pair<uint, uint>;
const uint INFINIT = 1e9;

struct Edge {
    uint to, cost;
};

std::vector<uint> dijkstra(uint s, std::vector<std::vector<Edge>>& graph) {
    uint n = graph.size();
    std::vector<uint> dist(n, INFINIT);
    dist[s] = 0;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> que;
    que.push(pii(0, s));

    while (!que.empty()) {
        pii p = que.top();
        que.pop();
        uint v = p.second;
        if (dist[v] < p.first) continue;
        for (auto& e : graph[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.push(pii(dist[e.to], e.to));
            }
        }
    }
    return dist;
}

int main() {
    uint n;
    std::scanf("%u", &n);
    std::vector<std::vector<Edge>> g(n);
    uint u, k, v, c;
    for (uint i = 0; i < n; ++i) {
        std::scanf("%u %u", &u, &k);
        g[u].resize(k);
        for (uint j = 0; j < k; ++j) {
            std::scanf("%u %u", &v, &c);
            g[u][j] = {v, c};
        }
    }
    std::vector<uint> dist = dijkstra(0, g);
    for (uint i = 0; i < n; ++i) {
        std::printf("%u %u\n", i, dist[i]);
    }
}
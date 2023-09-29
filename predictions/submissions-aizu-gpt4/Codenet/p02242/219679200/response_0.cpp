#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using uint = unsigned int;

struct edge { uint to, cost; };
using Graph = std::vector<std::vector<edge>>;

void dijkstra(const Graph &g, uint *dist, uint n) {
    const uint INFINIT = 100000 * (n - 1) + 1;
    std::fill_n(dist, n, INFINIT);
    std::vector<bool> visited(n, false);
    using P = std::pair<int, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    dist[0] = 0;
    que.push(P(0, 0));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        uint v = p.second;
        if (visited[v]) continue;
        visited[v] = true;
        for (auto &e : g[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main() {
    uint n;
    std::scanf("%u", &n);
    Graph g(n);
    for (auto i = 0u; i < n; ++i) {
        uint u, k, c, v;
        std::scanf("%u %u", &u, &k);
        for (auto j = 0u; j < k; ++j) {
            std::scanf("%u %u", &c, &v);
            g[u].push_back((edge){c, v});
        }
    }
    std::vector<uint> dist(n);
    dijkstra(g, dist.data(), n);
    for (auto i = 0u; i < n; ++i) {
        std::printf("%u %u\n", i, dist[i]);
    }
}
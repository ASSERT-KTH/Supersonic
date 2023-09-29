#include <vector>
#include <queue>
#include <iostream>
#include <limits>

template <typename Weight>
class Dinic {
public:
    struct Edge {
        int src, dst, rev;
        Weight weight;
        Edge(int f, int t, Weight cap, int rev = 0)
                : src(f), dst(t), rev(rev), weight(cap) {}
    };

    explicit Dinic(int n) : n(n), g(n), INF(std::numeric_limits<Weight>::max()) {}

    void add_edge(int src, int dst, Weight cap) {
        g[src].emplace_back(src, dst, cap, g[dst].size());
        g[dst].emplace_back(dst, src, 0, g[src].size() - 1);
    }

    Weight MaximumFlow(int s, int t) {
        Weight flow = 0;
        while (true) {
            std::vector<int> level(n, -1), iter(n);
            Bfs(s, level);
            if (level[t] == -1)
                break;
            Weight f;
            while ((f = Dfs(level, iter, s, t, INF)) > 0)
                flow += f;
        }
        return flow;
    }

private:
    const Weight INF;
    int n;
    std::vector<std::vector<Edge>> g;

    void Bfs(int s, std::vector<int>& level) {
        std::queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &e : g[v]) {
                if (e.weight > 0 && level[e.dst] == -1) {
                    level[e.dst] = level[v] + 1;
                    que.push(e.dst);
                }
            }
        }
    }

    Weight Dfs(std::vector<int>& level, std::vector<int>& iter, int v, int t, Weight flow) {
        if (v == t)
            return flow;
        for (int &i = iter[v]; i < g[v].size(); ++i) {
            Edge &e = g[v][i];
            if (e.weight > 0 && level[v] < level[e.dst]) {
                Weight d = Dfs(level, iter, e.dst, t, std::min(flow, e.weight));
                if (d > 0) {
                    e.weight -= d;
                    g[e.dst][e.rev].weight += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m, u, v, c;
    std::cin >> n >> m;
    Dinic<int> flow(n);
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }
    std::cout << flow.MaximumFlow(0, n - 1) << '\n';
    return 0;
}
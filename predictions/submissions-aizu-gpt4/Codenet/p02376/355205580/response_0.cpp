#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <iostream>

class Dinic {
public:
    Dinic(const int n) : n(n), g(n), INF(std::numeric_limits<int>::max()) {}
    void add_edge(const int src, const int dst, const int cap) {
        g[src].emplace_back(Edge(src, dst, cap, g[dst].size()));
        g[dst].emplace_back(Edge(dst, src, 0, g[src].size() - 1));
    }
    int MaximumFlow(const int s, const int t) {
        int flow = 0;
        std::vector<int> level(n), iter(n);
        while (true) {
            std::fill(level.begin(), level.end(), -1);
            Bfs(s, level);
            if (level[t] == -1)
                break;
            std::fill(iter.begin(), iter.end(), 0);
            for (int f; (f = Dfs(level, iter, s, t, INF)) > 0;)
                flow += f;
        }
        return flow;
    }

private:
    struct Edge {
        int src, dst, rev, weight;
        Edge(int src, int dst, int weight, int rev) : src(src), dst(dst), weight(weight), rev(rev) {}
    };

    int n;
    std::vector<std::vector<Edge>> g;
    const int INF;

    void Bfs(const int s, std::vector<int> &level) {
        std::queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (Edge &e : g[v]) {
                if (e.weight > 0 && level[e.dst] == -1) {
                    level[e.dst] = level[v] + 1;
                    que.push(e.dst);
                }
            }
        }
    }

    int Dfs(std::vector<int> &level, std::vector<int> &iter, int v, int t, int flow) {
        if (v == t)
            return flow;
        for (int &i = iter[v]; i < g[v].size(); ++i) {
            Edge &e = g[v][i];
            if (e.weight > 0 && level[v] < level[e.dst]) {
                int d = Dfs(level, iter, e.dst, t, std::min(flow, e.weight));
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
    std::cin.tie(NULL);
    int n, m, u, v, c;
    std::cin >> n >> m;
    Dinic flow(n);
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }
    std::cout << flow.MaximumFlow(0, n - 1) << '\n';
    return 0;
}
#include <vector>
#include <queue>
#include <iostream>
#include <limits>
using namespace std;

template <typename Weight>
class Dinic {
public:
    struct Edge {
        int src, dst, rev;
        Weight weight;
        Edge(int s, int d, Weight w, int r)
            : src(s), dst(d), rev(r), weight(w) {}
    };

    Dinic(int n) : n(n), g(n), INF(numeric_limits<Weight>::max()) {}

    void add_edge(int src, int dst, Weight cap) {
        g[src].emplace_back(src, dst, cap, g[dst].size());
        g[dst].emplace_back(dst, src, 0, g[src].size() - 1);
    }

    Weight MaximumFlow(int s, int t) {
        Weight maxFlow = 0;
        vector<int> level(n), iter(n);

        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0; // Level of source vertex

            queue<int> q;
            q.push(s);

            // Breadth-First Search
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (Edge &e : g[v]) {
                    if (e.weight > 0 && level[e.dst] == -1) {
                        level[e.dst] = level[v] + 1;
                        q.push(e.dst);
                    }
                }
            }

            if (level[t] == -1) {
                break;
            }

            fill(iter.begin(), iter.end(), 0);

            Weight flow;
            while ((flow = Dfs(s, t, INF, level, iter)) > 0) {
                maxFlow += flow;
            }
        }
        return maxFlow;
    }

private:
    int n;
    vector<vector<Edge>> g;
    Weight INF;

    Weight Dfs(int v, int t, Weight f, vector<int>& level, vector<int>& iter) {
        if (v == t) {
            return f;
        }
        for (int &i = iter[v]; i < g[v].size(); i++) {
            Edge &e = g[v][i];
            if (e.weight > 0 && level[v] < level[e.dst]) {
                Weight d = Dfs(e.dst, t, min(f, e.weight), level, iter);
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Dinic<int> flow(n);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }

    cout << flow.MaximumFlow(0, n - 1) << '\n';
    return 0;
}
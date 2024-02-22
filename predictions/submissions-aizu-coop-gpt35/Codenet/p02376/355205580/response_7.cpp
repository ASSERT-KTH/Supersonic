#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

template <typename Weight>
class Dinic {
public:
    Dinic(const int n) : n(n), nodes(n), INF(numeric_limits<Weight>::max()) {}

    void add_edge(const int src, const int dst, const Weight cap) {
        nodes[src].edges.emplace_back(dst, cap, nodes[dst].edges.size());
        nodes[dst].edges.emplace_back(src, 0, nodes[src].edges.size() - 1);
    }

    Weight MaximumFlow(const int s, const int t) {
        Weight flow = 0;
        while (true) {
            vector<int> level(n, -1), iter(n);
            Bfs(s, level);
            if (level[t] == -1)
                break;
            for (Weight f = 0; (f = Dfs(level, iter, s, t, INF)) > 0;)
                flow += f;
        }
        return flow;
    }

private:
    struct Edge {
        int dst, rev;
        Weight cap;
        Edge(int dst, Weight cap, int rev)
            : dst(dst), cap(cap), rev(rev) {}
    };

    struct Node {
        vector<Edge> edges;
    };

    int n;
    vector<Node> nodes;
    const Weight INF;

    void Bfs(const int s, vector<int>& level) {
        queue<int> que;
        for (level[s] = 0, que.push(s); !que.empty();) {
            const int v = que.front();
            que.pop();
            for (const auto& e : nodes[v].edges) {
                if (e.cap > 0 && level[e.dst] == -1) {
                    level[e.dst] = level[v] + 1;
                    que.push(e.dst);
                }
            }
        }
    }

    Weight Dfs(vector<int>& level, vector<int>& iter, int v, int t, Weight flow) {
        if (v == t)
            return flow;
        for (int& i = iter[v], N = nodes[v].edges.size(); i < N; ++i) {
            Edge& e = nodes[v].edges[i];
            if (e.cap > 0 && level[v] < level[e.dst]) {
                Weight d = Dfs(level, iter, e.dst, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    nodes[e.dst].edges[e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, u, v, c;
    cin >> n >> m;

    Dinic<int> flow(n);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }

    cout << flow.MaximumFlow(0, n - 1) << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to;
    int idx;
};

struct Node {
    int dist;
    std::vector<Edge> edges;
};

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<Node> nodes(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        nodes[a].edges.push_back({b, i});
        nodes[b].edges.push_back({a, i});
    }

    std::vector<int> dist(n + 1, 999999);
    dist[1] = 0;

    std::deque<int> Q;
    Q.push_back(1);
    while (!Q.empty()) {
        int a1 = Q.front();
        Q.pop_front();
        for (const auto& edge : nodes[a1].edges) {
            if (dist[edge.to] > dist[a1] + 1) {
                dist[edge.to] = dist[a1] + 1;
                Q.push_back(edge.to);
            }
        }
    }

    std::vector<std::vector<Edge>> y(n + 1);
    for (int i = 1; i <= n; i++) {
        for (const auto& edge : nodes[i].edges) {
            if (dist[i] < dist[edge.to]) {
                y[i].push_back(edge);
                nodes[edge.to].dist++;
            }
        }
    }

    std::vector<bool> used(m);
    std::vector<int> U(n + 1);
    int cnt = 0;

    for (int i = 0; i < q; i++) {
        int c;
        std::cin >> c;
        c--;

        std::deque<Edge> Q1;
        int ss = -1;
        if (dist[a[c]] < dist[b[c]])
            ss = b[c];
        if (dist[a[c]] > dist[b[c]])
            ss = a[c];
        if (ss >= 1 && U[ss] == 0 && !used[c]) {
            Q1.push_back({ss, c});
            while (!Q1.empty()) {
                int a1 = Q1.front().to;
                int a2 = Q1.front().idx;
                Q1.pop_front();
                if (U[a1] == 1 || used[a2])
                    continue;
                nodes[a1].dist--;
                used[a2] = true;
                if (nodes[a1].dist != 0)
                    continue;
                cnt++;
                U[a1] = 1;
                for (const auto& edge : y[a1]) {
                    if (U[edge.to] == 0)
                        Q1.push_back(edge);
                }
            }
        }
        std::cout << cnt << '\n';
    }

    return 0;
}
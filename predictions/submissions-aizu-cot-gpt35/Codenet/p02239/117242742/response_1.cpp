#include <iostream>
#include <vector>
#include <queue>

const int MAX_SIZE = 105;

void bfs(int s, const std::vector<std::vector<bool>>& m, std::vector<bool>& v, std::vector<int>& d) {
    v[s] = true;
    d[s] = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < m.size(); i++) {
            if (m[u][i] && !v[i]) {
                d[i] = d[u] + 1;
                v[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<bool>> m(n, std::vector<bool>(n, false));
    std::vector<bool> v(n, false);
    std::vector<int> d(n, -1);
    m.reserve(n);
    v.reserve(n);
    d.reserve(n);

    for (int i = 0; i < n; i++) {
        int u, k;
        std::cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            std::cin >> v;
            m[u - 1][v - 1] = true;
        }
    }

    bfs(0, m, v, d);

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ' ' << d[i] << std::endl;
    }

    return 0;
}
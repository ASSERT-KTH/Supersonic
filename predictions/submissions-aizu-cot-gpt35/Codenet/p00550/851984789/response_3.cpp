#include <iostream>
#include <vector>
#include <queue>
#include <array>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<std::pair<int, int>>> x(n + 1);
    std::vector<std::vector<std::pair<int, int>>> y(n + 1);
    std::array<int, 110000> dist;
    std::array<int, 110000> T;
    std::array<int, 110000> U;
    std::array<bool, 210000> used;

    std::vector<int> a(m);
    std::vector<int> b(m);

    for (int i = 0; i < m; i++) {
        std::cin >> a[i] >> b[i];
        x[a[i]].emplace_back(b[i], i);
        x[b[i]].emplace_back(a[i], i);
    }

    dist.fill(999999);
    dist[1] = 0;
    std::queue<int> Q;
    Q.push(1);

    while (!Q.empty()) {
        int a1 = Q.front();
        Q.pop();
        for (auto& i : x[a1]) {
            if (dist[i.first] > dist[a1] + 1) {
                dist[i.first] = dist[a1] + 1;
                Q.push(i.first);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto& j : x[i]) {
            y[i].emplace_back(j);
            T[j.first]++;
        }
    }

    for (int i = 0; i < q; i++) {
        int c;
        std::cin >> c;
        c--;

        std::vector<std::pair<int, int>> Q1;
        int ss = -1;
        if (dist[a[c]] < dist[b[c]])
            ss = b[c];
        if (dist[a[c]] > dist[b[c]])
            ss = a[c];
        if (ss >= 1 && U[ss] == 0 && used[c] == false) {
            Q1.emplace_back(ss, c);
            while (!Q1.empty()) {
                int a1 = Q1.front().first;
                int a2 = Q1.front().second;
                Q1.erase(Q1.begin());
                if (U[a1] == 1 || used[a2] == true)
                    continue;
                T[a1]--;
                used[a2] = true;
                if (T[a1] != 0)
                    continue;
                U[a1] = 1;
                for (auto& j : y[a1]) {
                    if (U[j.first] == 0)
                        Q1.emplace_back(j);
                }
            }
        }
        std::cout << Q1.size() << '\n';
    }

    return 0;
}
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

constexpr int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, l, k, a, h, t1, t2, t3;
    while (std::cin >> n >> m >> l >> k >> a >> h, n) {
        std::set<int> rei {a, h};
        std::vector<std::vector<int>> b(n, std::vector<int>(n, INF));
        std::vector<std::vector<int>> x(n, std::vector<int>(n, INF));
        for (int i = 0; i < l; ++i) {
            std::cin >> t1;
            rei.insert(t1);
        }
        for (int i = 0; i < k; ++i) {
            std::cin >> t1 >> t2 >> t3;
            b[t1][t2] = b[t2][t1] = t3;
        }
        for (int o = 0; o < n; ++o) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    b[i][j] = std::min(b[i][j], b[i][o] + b[o][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (rei.count(i) > 0) {
                for (int j = 0; j < n; ++j) {
                    if (rei.count(j) > 0 && b[i][j] <= m) {
                        x[i][j] = b[i][j];
                    }
                }
            }
        }
        for (int o = 0; o < n; ++o) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    x[i][j] = std::min(x[i][j], x[i][o] + x[o][j]);
                }
            }
        }
        if (x[a][h] >= INF) {
            std::cout << "Help!\n";
        } else if (x[a][h] < m) {
            std::cout << x[a][h] << '\n';
        } else {
            std::cout << x[a][h] * 2 - m << '\n';
        }
    }
    return 0;
}
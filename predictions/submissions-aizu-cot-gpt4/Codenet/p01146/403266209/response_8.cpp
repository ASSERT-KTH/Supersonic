#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <limits>

constexpr int INF = std::numeric_limits<int>::max();

int main() {
    int n, m, l, k, a, h, t1, t2, t3;
    while (std::cin >> n >> m >> l >> k >> a >> h) {
        std::set<int> rei;
        rei.insert(a);
        rei.insert(h);
        std::vector<std::vector<int>> b(n, std::vector<int>(n, INF));
        std::vector<std::vector<int>> x(n, std::vector<int>(n, INF));
        int re;
        for (int i = 0; i < l; i++) {
            std::cin >> re;
            rei.insert(re);
        }
        for (int i = 0; i < k; i++) {
            std::cin >> t1 >> t2 >> t3;
            b[t1][t2] = b[t2][t1] = t3;
        }
        for (int o = 0; o < n; o++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = std::min(b[i][j], b[i][o] + b[o][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (rei.count(i)) {
                for (int j = 0; j < n; j++) {
                    if (rei.count(j) && b[i][j] <= m) {
                        x[i][j] = b[i][j];
                    }
                }
            }
        }
        for (int o = 0; o < n; o++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    x[i][j] = std::min(x[i][j], x[i][o] + x[o][j]);
                }
            }
        }
        std::cout << (x[a][h] >= INF ? "Help!" : (x[a][h] < m ? std::to_string(x[a][h]) : std::to_string(x[a][h] * 2 - m))) << std::endl;
    }
}
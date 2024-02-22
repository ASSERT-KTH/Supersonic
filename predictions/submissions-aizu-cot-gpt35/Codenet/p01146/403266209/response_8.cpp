#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int main() {
    int n, m, l, k, a, h, t1, t2, t3;
    while (std::cin >> n >> m >> l >> k >> a >> h, n) {
        std::vector<bool> rei(n, false);
        rei[a] = true;
        rei[h] = true;
        
        std::vector<std::vector<int>> b(n, std::vector<int>(n, INF));
        std::vector<std::vector<int>> x(n, std::vector<int>(n, INF));
        
        for (int i = 0; i < l; i++) {
            int re;
            std::cin >> re;
            rei[re] = true;
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
            if (rei[i]) {
                for (int j = 0; j < n; j++) {
                    if (rei[j] && b[i][j] <= m) {
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
        
        int result = x[a][h];
        if (result >= INF) {
            std::cout << "Help!" << std::endl;
        } else if (result < m) {
            std::cout << result << std::endl;
        } else {
            std::cout << result * 2 - m << std::endl;
        }
    }
    return 0;
}
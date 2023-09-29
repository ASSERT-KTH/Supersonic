#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

constexpr int inf = 1e9;
constexpr int64_t inf64 = 1e18;
constexpr double eps = 1e-9;

void solve(int n, int m) {
    std::vector<std::string> e(n);
    std::string ts;
    int concatenated_len = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> e[i];
        concatenated_len += e[i].size();
    }
    for (int i = 0; i < m; ++i) {
        std::string t;
        std::cin >> t;
        ts += t;
    }
    std::vector<int> sum_len(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1)
                sum_len[i] += e[j].size();
        }
    }
    std::vector<std::vector<bool>> p(ts.size(), std::vector<bool>(1 << n, false));
    std::vector<std::vector<int>> heads(ts.size());
    for (int i = 0; i < ts.size(); ++i) {
        p[i][0] = true;
        for (int j = 0; j < n; ++j) {
            if (i + e[j].size() <= ts.size() && e[j] == ts.substr(i, e[j].size())) {
                p[i][1 << j] = true;
                heads[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int i = ts.size() - 1; i >= 0; --i) {
        for (int j = 1; j < (1 << n); ++j) {
            if (!p[i][j] && i + sum_len[j] <= ts.size()) {
                for (int k : heads[i]) {
                    if ((j >> k) & 1 && p[i + e[k].size()][j & (~(1 << k))]) {
                        p[i][j] = true;
                        break;
                    }
                }
            }
        }
        if (p[i][(1 << n) - 1])
            ++ans;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(10);
    while (true) {
        int n, m;
        std::cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solve(n, m);
    }
    return 0;
}
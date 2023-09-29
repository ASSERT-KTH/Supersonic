#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, x, y) for (int i = (x); i < (y); ++i)

const int inf = 1e9;
const long long inf64 = 1e18;
const double eps = 1e-9;

void solve(int n, int m) {
    std::vector<std::string> e(n);
    std::string ts;
    int concatenated_len = 0;
    rep(i, 0, n) {
        std::cin >> e[i];
        concatenated_len += e[i].size();
    }
    rep(i, 0, m) {
        std::string t;
        std::cin >> t;
        ts += t;
    }
    std::vector<int> sum_len(1 << n);
    rep(i, 0, 1 << n) {
        rep(j, 0, n) {
            if (((i >> j) & 1) == 0) continue;
            sum_len[i] += e[j].size();
        }
    }
    std::vector<std::vector<bool>> p(5000, std::vector<bool>(1 << 12, false));
    std::vector<std::vector<int>> heads(ts.size());
    rep(i, 0, ts.size()) {
        p[i][0] = true;
        rep(j, 0, n) {
            if (i + e[j].size() > ts.size() || e[j] != ts.substr(i, e[j].size())) continue;
            p[i][1 << j] = true;
            heads[i].push_back(j);
        }
    }
    int ans = 0;
    for (int i = ts.size() - 1; i >= 0; --i) {
        rep(j, 1, 1 << n) {
            if (p[i][j] || i + sum_len[j] > ts.size()) continue;
            for (int k : heads[i]) {
                if (((j >> k) & 1) == 0) continue;
                int i2 = i + e[k].size();
                if (p[i2][j & (~(1 << k))]) {
                    p[i][j] = true;
                    break;
                }
            }
        }
        if (p[i][(1 << n) - 1]) ++ans;
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(10);
    for (;;) {
        int n, m;
        std::cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve(n, m);
    }
    return 0;
}
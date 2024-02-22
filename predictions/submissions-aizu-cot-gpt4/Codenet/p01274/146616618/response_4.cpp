#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

constexpr int INF = 1e9;
constexpr int N = 100000;
using P = std::pair<int, int>;
using ll = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m, hp[101];
    while (std::cin >> n, n) {
        for (int i = 0; i < n; ++i)
            std::cin >> hp[i];
        std::vector<P> mg[2];
        mg[0].reserve(N);
        mg[1].reserve(N);
        std::cin >> m;
        for (int i = 0, cost, dam; i < m; ++i) {
            std::string name, type;
            std::cin >> name >> cost >> type >> dam;
            if (dam)
                mg[type == "All"].push_back(P(dam, cost));
        }
        int dp[2][N + 10] = {};
        for (int i = 0; i < 2; ++i)
            for (int j = 1; j < N + 10; ++j)
                dp[i][j] = INF;
        for (int k = 0; k < 2; ++k)
            for (size_t i = 0; i < mg[k].size(); ++i)
                for (int j = mg[k][i].first; j <= (N / mg[k][i].first + 1) * mg[k][i].first; ++j)
                    dp[k][std::min(N, j)] = std::min(dp[k][std::min(N, j)], dp[k][j - mg[k][i].first] + mg[k][i].second);
        for (int i = 0; i < 2; ++i)
            for (int j = N; j >= 0; --j)
                dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);
        ll ans = INF;
        for (int i = 0; i <= N; ++i) {
            ll cost = dp[1][i];
            for (int j = 0; j < n; ++j)
                cost += dp[0][std::max(0, hp[j] - i)];
            ans = std::min(ans, cost);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
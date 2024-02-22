#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9
#define N 100000

typedef std::pair<int, int> P;
typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false); // Makes IO operations faster
    std::cin.tie(NULL);

    int n, m, hp[101];
    while (std::cin >> n, n) {
        for (int i = 0; i < n; i++)
            std::cin >> hp[i];
        std::vector<P> mg[2];
        std::cin >> m;
        for (int i = 0, cost, dam; i < m; i++) {
            std::string name, type;
            std::cin >> name >> cost >> type >> dam;
            if (dam)
                mg[type == "All"].push_back(P(dam, cost));
        }
        int dp[2][N + 10] = {};
        for (int i = 0; i < 2; i++)
            for (int j = 1; j < N + 10; j++)
                dp[i][j] = INF;
        for (int k = 0; k < 2; k++)
            for (size_t i = 0; i < mg[k].size(); i++)
                for (int j = mg[k][i].first; j <= N; j += mg[k][i].first) // Avoid unnecessary loop iterations
                    dp[k][j] = std::min(dp[k][j], dp[k][j - mg[k][i].first] + mg[k][i].second);
        for (int i = 0; i < 2; i++)
            for (int j = N - 1; j >= 0; j--) // Start from N - 1 to avoid accessing beyond array bounds
                dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);
        ll ans = INF;
        for (int i = 0; i <= N; i++) {
            ll cost = dp[1][i];
            for (int j = 0; j < n; j++) {
                int temp = std::max(0, hp[j] - i); // Store result to avoid repeated calculation
                cost += dp[0][temp];
            }
            ans = std::min(ans, cost);
        }
        std::cout << ans << "\n"; // Use '\n' instead of endl to avoid unnecessary flush operations
    }
    return 0;
}
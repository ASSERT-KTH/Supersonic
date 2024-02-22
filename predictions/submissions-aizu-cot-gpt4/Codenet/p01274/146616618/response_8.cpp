#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const int INF = 1e9;
const int N = 100000;

struct Magic {
    int damage;
    int cost;
};

int main() {
    int n, m;
    while (std::cin >> n, n) {
        int* hp = new int[n];
        for (int i = 0; i < n; i++)
            std::cin >> hp[i];
        std::vector<Magic> mg[2];
        std::cin >> m;
        for (int i = 0, cost, dam; i < m; i++) {
            std::string name, type;
            std::cin >> name >> cost >> type >> dam;
            if (dam)
                mg[type == "All"].push_back({dam, cost});
        }
        int dp[2][N + 10] = {};
        for (int i = 0; i < 2; i++)
            std::fill(dp[i] + 1, dp[i] + N + 10, INF);
        for (int k = 0; k < 2; k++)
            for (int i = 0; i < mg[k].size(); i++)
                for (int j = mg[k][i].damage; j <= (N / mg[k][i].damage + 1) * mg[k][i].damage; j++)
                    dp[k][std::min(N, j)] = std::min(dp[k][std::min(N, j)], dp[k][j - mg[k][i].damage] + mg[k][i].cost);
        for (int i = 0; i < 2; i++)
            for (int j = N; j >= 0; j--)
                dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);
        long long ans = INF;
        for (int i = 0; i <= N; i++) {
            long long cost = dp[1][i];
            for (int j = 0; j < n; j++)
                cost += dp[0][std::max(0, hp[j] - i)];
            ans = std::min(ans, cost);
        }
        std::cout << ans << std::endl;
        delete[] hp;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

const int INF = 1e9;
const int N = 100000;

typedef std::pair<int, int> P;
typedef long long ll;

int main() {
    int n, m, hp[101];
    while (std::cin >> n, n) {
        for (int i = 0; i < n; i++)
            std::cin >> hp[i];
        std::array<std::vector<P>, 2> mg;
        
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
            for (int i = 0; i < mg[k].size(); i++) {
                int range = (N / mg[k][i].first + 1) * mg[k][i].first;
                for (int j = mg[k][i].first; j <= range; j++) {
                    int min_val = std::min(N, j);
                    dp[k][min_val] = std::min(dp[k][min_val], dp[k][j - mg[k][i].first] + mg[k][i].second);
                }
            }
        
        for (int i = 0; i < 2; i++)
            for (int j = N; j >= 0; j--)
                dp[i][j] = std::min(dp[i][j], dp[i][j + 1]);
        
        ll ans = INF;
        for (int i = 0; i <= N; i++) {
            ll cost = dp[1][i];
            for (int j = 0; j < n; j++)
                cost += dp[0][std::max(0, hp[j] - i)];
            ans = std::min(ans, cost);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
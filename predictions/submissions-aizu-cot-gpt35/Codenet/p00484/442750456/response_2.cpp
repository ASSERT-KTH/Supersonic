#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;
typedef std::pair<int, int> P;

bool compare(const P& a, const P& b) {
    return a.first < b.first;
}

int main() {
    int n, K;
    std::cin >> n >> K;
    std::vector<P> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i].first >> v[i].second;
        v[i].second--;
    }
    std::sort(v.begin(), v.end(), compare);

    std::vector<std::vector<ll>> d(15, std::vector<ll>(2005, 0));
    for (int i = 0; i < n; i++) {
        int j = v[i].second;
        for (int k = 1; k <= i + 1; k++) {
            d[j][k] += d[j][k - 1] + v[i].first + (k - 1) * 2;
        }
    }

    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(K + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            ll res = dp[i][j];
            for (int k = 0; k <= i + 1; k++) {
                if (j >= k) {
                    res = std::max(res, dp[i][j - k] + d[v[i].second][k]);
                }
            }
            dp[i + 1][j] = res;
        }
    }

    std::cout << dp[n][K] << std::endl;
    return 0;
}
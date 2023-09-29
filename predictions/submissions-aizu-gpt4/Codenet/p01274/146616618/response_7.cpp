#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define N 100000

using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main() {
    int n, m, hp[101];
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> hp[i];
        vector<P> mg[2];
        cin >> m;
        for (int i = 0, cost, dam; i < m; i++) {
            string name, type;
            cin >> name >> cost >> type >> dam;
            if (dam)
                mg[type == "All"].push_back(P(dam, cost));
        }
        vector<vector<int>> dp(2, vector<int>(N + 10, INF));
        for (int k = 0; k < 2; k++) {
            for (const auto &p : mg[k]) {
                for (int j = p.first; j <= N; j += p.first)
                    dp[k][j] = min(dp[k][j], dp[k][j - p.first] + p.second);
            }
            for (int j = N; j >= 0; j--)
                dp[k][j] = min(dp[k][j], dp[k][j + 1]);
        }
        ll ans = INF;
        for (int i = 0; i <= N; i++) {
            ll cost = dp[1][i];
            for (int j = 0; j < n; j++)
                cost += dp[0][max(0, hp[j] - i)];
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using P = pair<int, int>;
using ll = long long;

const int INF = 1e9;
const int N = 100000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, hp[101];
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> hp[i];

        vector<P> mg[2];
        cin >> m;
        for (int i = 0, cost, dam; i < m; i++) {
            string name, type;
            cin >> name >> cost >> type >> dam;
            mg[type == "All"].push_back(P(dam, cost));
        }

        int dp[2][N + 10] = {};
        for (int i = 0; i < 2; i++)
            for (int j = 1; j < N + 10; j++)
                dp[i][j] = INF;
        for (int k = 0; k < 2; k++)
            for (int i = 0; i < mg[k].size(); i++)
                for (int j = mg[k][i].first; j <= (N / mg[k][i].first + 1) * mg[k][i].first; j++) {
                    int index = min(N, j);
                    dp[k][index] = min(dp[k][index], dp[k][j - mg[k][i].first] + mg[k][i].second);
                }
        for (int i = 0; i < 2; i++)
            for (int j = N; j >= 0; j--)
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);

        ll ans = INF;
        for (int i = 0; i <= N; i++) {
            ll cost = dp[1][i];
            for (int j = 0; j < n; j++) {
                int index = max(0, hp[j] - i);
                cost += dp[0][index];
            }
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    return 0;
}
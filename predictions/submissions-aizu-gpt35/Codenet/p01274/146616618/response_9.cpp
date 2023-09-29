#include <bits/stdc++.h>
#define INF 1e9
#define f first
#define s second
#define N 100000
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int hp[101];
vector<P> mg[2];
int dp[2][N + 10] = {};

void solve() {
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin >> n;
    if (n == 0) {
        exit(0);
    }
    for (int i = 0; i < n; i++)
        cin >> hp[i];
    cin >> m;
    for (int i = 0, cost, dam; i < m; i++) {
        string name, type;
        cin >> name >> cost >> type >> dam;
        if (dam)
            mg[type == "All"].push_back(P(dam, cost));
    }
    for (int i = 0; i < 2; i++)
        for (int j = 1; j < N + 10; j++)
            dp[i][j] = INF;
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < mg[k].size(); i++)
            for (int j = mg[k][i].f; j <= (N / mg[k][i].f + 1) * mg[k][i].f; j++)
                dp[k][min(N, j)] = min(dp[k][min(N, j)], dp[k][j - mg[k][i].f] + mg[k][i].s);
    for (int i = N - 1; i >= 0; i--)
        for (int j = 0; j < 2; j++)
            dp[j][i] = min(dp[j][i], dp[j][i + 1]);
    ll ans = INF;
    for (int i = 0; i <= N; i++) {
        ll cost = dp[1][i];
        for (int j = 0; j < n; j++)
            cost += dp[0][max(0, hp[j] - i)];
        ans = min(ans, cost);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        solve();
    }
    return 0;
}
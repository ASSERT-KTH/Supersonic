#include <bits/stdc++.h>
#define INF 1e9
#define f first
#define s second
#define N 100000
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int main() {
  ios_base::sync_with_stdio(0);
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
      if (dam)
        mg[type == "All"].push_back(P(dam, cost));
    }
    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INF;
    for (int k = 0; k < 2; k++)
      for (auto &p : mg[k])
        for (int j = p.f; j <= (N / p.f + 1) * p.f; j++)
          dp[k][min(N, j)] = min(dp[k][min(N, j)], dp[k][j - p.f] + p.s);
    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--)
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
    ll ans = INF;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    cout << ans << '\n';
  }
  return 0;
}
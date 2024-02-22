#include <bits/stdc++.h>
#define INF 1e9
#define f first
#define s second
#define N 100000
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, hp[101];
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> hp[i];
    array<vector<P>, 2> mg;
    cin >> m;
    for (int i = 0, cost, dam; i < m; i++) {
      string name, type;
      cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].push_back(P(dam, cost));
    }
    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      fill(dp[i] + 1, dp[i] + N + 10, INF);
    for (int k = 0; k < 2; k++)
      for (auto& scroll : mg[k]) {
        for (int j = scroll.f; j <= (N / scroll.f + 1) * scroll.f; j++)
          dp[k][min(N, j)] =
              min(dp[k][min(N, j)], dp[k][j - scroll.f] + scroll.s);
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
    cout << ans << '\n';
  }
  return 0;
}
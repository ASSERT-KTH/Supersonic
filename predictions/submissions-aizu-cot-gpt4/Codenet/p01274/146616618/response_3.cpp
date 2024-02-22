#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

#define INF 1e9
#define N 100000

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, hp[101];
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> hp[i];

    array<vector<pair<int, int>>, 2> mg;
    cin >> m;
    mg[0].reserve(m);
    mg[1].reserve(m);

    for (int i = 0, cost, dam; i < m; i++) {
      string name, type;
      cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].emplace_back(dam, cost);
    }

    array<array<int, N + 10>, 2> dp{};
    for (int i = 0; i < 2; i++)
      fill_n(dp[i].begin() + 1, N + 10 - 1, INF);

    for (int k = 0; k < 2; k++)
      for (const auto &p : mg[k])
        for (int j = p.first; j <= (N / p.first + 1) * p.first; j++) {
          int min_j = min(N, j);
          dp[k][min_j] = min(dp[k][min_j], dp[k][j - p.first] + p.second);
        }

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

    cout << ans << endl;
  }

  return 0;
}
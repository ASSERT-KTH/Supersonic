#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

constexpr int INF = 1e9;
constexpr int N = 100000;

using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main() {
  int n, m, hp[101] = {};
  vector<P> mg[2];

  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> hp[i];
    cin >> m;

    for (int i = 0, cost, dam; i < m; i++) {
      string name, type;
      cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].emplace_back(dam, cost);
    }

    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      fill_n(dp[i] + 1, N + 9, INF);

    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].first, bound = min(N, (N / mg[k][i].first + 1) * mg[k][i].first); j <= bound; j++)
          dp[k][j] = min(dp[k][j], dp[k][j - mg[k][i].first] + mg[k][i].second);

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

    mg[0].clear();
    mg[1].clear();
  }
  return 0;
}
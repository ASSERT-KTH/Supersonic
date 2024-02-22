#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define INF 1e9

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int main() {
  int n, m;
  while (cin >> n, n) {
    vector<int> hp(n);
    for (int i = 0; i < n; i++)
      cin >> hp[i];

    vector<vector<P>> mg(2);
    cin >> m;
    mg[0].reserve(m);
    mg[1].reserve(m);
    for (int i = 0, cost, dam; i < m; i++) {
      string name, type;
      cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].emplace_back(dam, cost);
    }

    int maxHp = *max_element(hp.begin(), hp.end());
    vector<vector<int>> dp(2, vector<int>(maxHp + 10, INF));
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].first; j <= maxHp; j++)
          dp[k][min(maxHp, j)] =
              min(dp[k][min(maxHp, j)], dp[k][j - mg[k][i].first] + mg[k][i].second);

    for (int i = 0; i < 2; i++)
      for (int j = maxHp; j >= 0; j--)
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);

    ll ans = INF;
    for (int i = 0; i <= maxHp; i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
  return 0;
}
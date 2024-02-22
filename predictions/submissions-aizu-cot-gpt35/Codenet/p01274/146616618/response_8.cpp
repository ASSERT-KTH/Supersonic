#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int N = 100000;

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
    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= N; j++)
        dp[i][j] = N * 100;
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].f; j <= (N / mg[k][i].f + 1) * mg[k][i].f; j++)
          dp[k][j] = min(dp[k][j], dp[k][j - mg[k][i].f] + mg[k][i].s);
    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--)
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
    ll ans = N * 100;
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
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define N 100000

using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

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
    int dp[2][N + 1] = {};
    for (int i = 0; i < 2; i++)
      fill(dp[i] + 1, dp[i] + N + 1, INF);
    
    for (int k = 0; k < 2; k++)
      for (const auto &p : mg[k])
        for (int j = p.first; j <= N; j++)
          dp[k][j] = min(dp[k][j], dp[k][j - p.first] + p.second);
    
    for (int i = 0; i < 2; i++)
      for (int j = N - 1; j >= 0; j--)
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
    
    ll ans = INF;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    cout << ans << "\n";
  }
  return 0;
}
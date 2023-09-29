#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define N 100000
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
    vector<vector<int>> dp(2, vector<int>(N+1, INT_MAX));
    for (int k = 0; k < 2; k++) {
      dp[k][0] = 0;
      for (auto& magic : mg[k]) {
        for (int j = magic.first; j <= N; j++) {
          dp[k][j] = min(dp[k][j], dp[k][j - magic.first] + magic.second);
        }
      }
      for (int j = N-1; j >= 0; j--) {
        dp[k][j] = min(dp[k][j], dp[k][j+1]);
      }
    }
    ll ans = INT_MAX;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++) {
        cost += dp[0][max(0, hp[j] - i)];
      }
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
  return 0;
}
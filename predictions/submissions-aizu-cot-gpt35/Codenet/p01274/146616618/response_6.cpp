#include <iostream>
#include <vector>
#include <string>
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
    
    vector<P> mg0, mg1;
    cin >> m;
    for (int i = 0, cost, dam; i < m; i++) {
      string name, type;
      cin >> name >> cost >> type >> dam;
      if (dam)
        (type == "All" ? mg1 : mg0).push_back(P(dam, cost));
    }
    
    vector<vector<int>> dp(2, vector<int>(N + 10));
    
    for (int k = 0; k < 2; k++) {
      int minDamage = INF, maxDamage = 0;
      for (int i = 0; i < mg[k].size(); i++) {
        minDamage = min(minDamage, mg[k][i].f);
        maxDamage = max(maxDamage, mg[k][i].f);
      }
      for (int j = minDamage; j <= (N / maxDamage + 1) * maxDamage; j++) {
        dp[k][min(N, j)] = INF;
      }
    }
    
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < mg[k].size(); i++) {
        for (int j = mg[k][i].f; j <= (N / mg[k][i].f + 1) * mg[k][i].f; j++) {
          dp[k][min(N, j)] = min(dp[k][min(N, j)], dp[k][j - mg[k][i].f] + mg[k][i].s);
        }
      }
    }
    
    for (int i = 0; i < 2; i++) {
      for (int j = N; j >= 0; j--) {
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      }
    }
    
    ll ans = INF;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[1][i];
      int minHp = INF, maxHp = 0;
      for (int j = 0; j < n; j++) {
        int diff = hp[j] - i;
        if (diff >= 0) {
          minHp = min(minHp, diff);
          maxHp = max(maxHp, diff);
        }
      }
      for (int j = minHp; j <= maxHp; j++) {
        cost += dp[0][j];
      }
      ans = min(ans, cost);
    }
    
    cout << ans << endl;
  }
  
  return 0;
}
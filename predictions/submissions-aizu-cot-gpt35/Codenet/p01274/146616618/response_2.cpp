#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#define N 100000
#define INF INT_MAX

typedef pair<int, int> P;
typedef long long ll;

int main() {
  int n, m;
  vector<int> hp(101);
  
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &hp[i]);
    
    vector<vector<P>> mg(2);
    scanf("%d", &m);
    for (int i = 0, cost, dam; i < m; i++) {
      string name, type;
      cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].push_back(P(dam, cost));
    }
    
    vector<vector<int>> dp(2, vector<int>(N + 10, INF));
    for (int i = 0; i < 2; i++)
      dp[i][0] = 0;
    
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < mg[k].size(); i++) {
        int f = mg[k][i].first;
        int c = mg[k][i].second;
        for (int j = f; j <= (N / f + 1) * f; j++) {
          int idx = min(N, j);
          dp[k][idx] = min(dp[k][idx], dp[k][idx - f] + c);
        }
      }
    }
    
    for (int i = 0; i < 2; i++) {
      for (int j = N; j >= 0; j--) {
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      }
    }
    
    ll ans = INF;
    for (int i = 0; i < hp.size(); i++) {
      ll cost = dp[1][0];
      for (int j = 0; j < n; j++) {
        int diff = hp[j] - i;
        cost += dp[0][max(0, diff)];
      }
      ans = min(ans, cost);
    }
    
    printf("%lld\n", ans);
  }
  
  return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#define INF 1e9
#define N 100000
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int main() {
  int n, m;
  while (cin >> n, n) {
    vector<int> hp(n);
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
    
    int dp[2][2] = {};
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].f; j <= (N / mg[k][i].f + 1) * mg[k][i].f; j++) {
          int min_j = min(N, j);
          dp[k][min_j] = min(dp[k][min_j], dp[k][j - mg[k][i].f] + mg[k][i].s);
        }
        
    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--)
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      
    ll ans = INF;
    for (int i = 0; i <= N - mg[1].size(); i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
  return 0;
}
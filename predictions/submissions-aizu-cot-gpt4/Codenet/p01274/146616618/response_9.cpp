#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define f first
#define s second
#define N 100000
using namespace std;
using P = pair<int, int>;
using ll = long long;
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
      int typeInt = (type == "All") ? 1 : 0;
      if (dam)
        mg[typeInt].push_back(P(dam, cost));
    }
    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INF;
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].f; j <= (N / mg[k][i].f + 1) * mg[k][i].f; j++) {
          int minVal = min(N, j);
          dp[k][minVal] = min(dp[k][minVal], dp[k][j - mg[k][i].f] + mg[k][i].s);
        }
    for (int i = 0; i < 2; i++) {
      int minVal = INF;
      for (int j = N; j >= 0; j--) {
        dp[i][j] = min(dp[i][j], minVal);
        minVal = dp[i][j];
      }
    }
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
#include <bits/stdc++.h>
#define INF 1e9
#define f first
#define s second
#define N 100000
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
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
        mg[type == "All"].emplace_back(dam, cost);
    }
    vector<int> dp[2](N + 10, INF);
    dp[0][0] = dp[1][0] = 0;
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = N; j >= mg[k][i].f; j--)
          dp[k][j] = min(dp[k][j], dp[k][j - mg[k][i].f] + mg[k][i].s);
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
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
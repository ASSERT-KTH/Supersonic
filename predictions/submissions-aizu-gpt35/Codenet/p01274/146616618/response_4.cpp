#include <bits/stdc++.h>
#define INF 1e9
#define f first
#define s second
#define N 100000
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

const int MAX_N = 100005;
int n, m, hp[MAX_N];
vector<P> mg[2];
int dp[2][MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> hp[i];
    cin >> m;
    for (int i = 0, cost, dam; i < m; i++) {
      string name, type;
      cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].push_back(P(dam, cost));
    }
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < MAX_N; j++)
        dp[i][j] = INF;
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].f; j <= (MAX_N / mg[k][i].f + 1) * mg[k][i].f; j++)
          dp[k][min(MAX_N - 1, j)] =
              min(dp[k][min(MAX_N - 1, j)], dp[k][j - mg[k][i].f] + mg[k][i].s);
    for (int i = 0; i < 2; i++)
      for (int j = MAX_N - 2; j >= 0; j--)
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
    ll ans = INF;
    for (int i = 0; i < MAX_N; i++) {
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
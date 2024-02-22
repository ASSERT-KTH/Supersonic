#include <bits/stdc++.h>
#define INF 1e9
#define f first
#define s second
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

    int dp[N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= N; j++)
        dp[j] = INF;

    int minCost[2][N + 10];
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= N; j++)
        minCost[i][j] = INF;

    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].f; j <= (N / mg[k][i].f + 1) * mg[k][i].f; j++)
          minCost[k][min(N, j)] =
              min(minCost[k][min(N, j)], minCost[k][j - mg[k][i].f] + mg[k][i].s);

    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--)
        minCost[i][j] = min(minCost[i][j], minCost[i][j + 1]);

    ll ans = INF;
    for (int i = 0; i <= N; i++) {
      ll cost = minCost[1][i];
      for (int j = 0; j < n; j++)
        cost += minCost[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }

    cout << ans << endl;
  }

  return 0;
}
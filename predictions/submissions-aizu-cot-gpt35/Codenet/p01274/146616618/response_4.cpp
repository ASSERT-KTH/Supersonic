#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int N = 100000;

int main() {
  int n, m, hp[101];
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &hp[i]);
    
    vector<P> mg;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      char name[101], type[101];
      int cost, dam;
      scanf("%s %d %s %d", name, &cost, type, &dam);
      if (dam)
        mg.push_back(P(dam, cost));
    }
    
    int dp[N + 10] = {};
    for (int j = 1; j < N + 10; j++)
      dp[j] = INF;
    
    for (int i = 0; i < mg.size(); i++) {
      for (int j = mg[i].f; j <= N + mg[i].f; j++) {
        dp[min(N, j)] = min(dp[min(N, j)], dp[j - mg[i].f] + mg[i].s);
      }
    }
    
    for (int j = N; j >= 0; j--)
      dp[j] = min(dp[j], dp[j + 1]);
    
    ll ans = INF;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[i];
      for (int j = 0; j < n; j++)
        cost += dp[max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    
    printf("%lld\n", ans);
  }
  return 0;
}
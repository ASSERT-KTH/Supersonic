#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000000;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  sort(c.begin() + 1, c.end());
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      dp[j] = min(dp[j], dp[j - c[i]] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
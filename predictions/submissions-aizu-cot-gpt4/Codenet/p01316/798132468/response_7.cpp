#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000
int dp[2][256];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  while (cin >> n >> m, n) {
    int b[m];
    int a[n + 1];
    r(i, m) cin >> b[i];
    r(i, n) cin >> a[i + 1];
    fill(dp[0], dp[0]+256, INF);
    dp[0][128] = 0;
    int cur = 1, pre = 0;
    r(i, n) {
      r(j, 256) if (dp[pre][j] != INF) {
        r(k, m) {
          int p = min(max(j + b[k],0),255);
          int diff = a[i + 1] - p;
          dp[cur][p] =
            min(dp[cur][p], dp[pre][j] + diff*diff);
        }
      }
      fill(dp[pre], dp[pre]+256, INF);
      swap(pre,cur);
    }
    cout << *min_element(dp[pre], dp[pre]+256) << endl;
  }
  return 0;
}
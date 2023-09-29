#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int mp[MAXN][MAXN], dp[MAXN][MAXN];
int h, w, n;
int dx[] = {0, 1}, dy[] = {1, 0};
void saiki(int x, int y) {
  if (y == h || x == w)
    cout << y + 1 << " " << x + 1 << endl;
  else
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (1) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        int cnt = dp[i][j] % 2;
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * cnt;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * cnt;
        mp[i][j] ^= cnt;
      }
    saiki(0, 0);
  }
  return 0;
}
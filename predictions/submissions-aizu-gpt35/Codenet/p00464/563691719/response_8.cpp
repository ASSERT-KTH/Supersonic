#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int mp[MAX][MAX], dp[MAX][MAX];
int h, w, n;
void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  if (y == h || x == w)
    cout << y + 1 << " " << x + 1 << endl;
  else
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
        int x = dp[i][j] / 2;
        dp[i][j + 1] += x + mp[i][j] * (dp[i][j] & 1);
        dp[i + 1][j] += x + !mp[i][j] * (dp[i][j] & 1);
        if (dp[i][j] & 1)
          mp[i][j] = !mp[i][j];
      }
    saiki(0, 0);
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int mp[1001][1001], dp[1001][1001];
int h, w, n;
void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  if (y == h || x == w)
    cout << y + 1 << " " << x + 1 << endl;
  else
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> h >> w >> n, h || w || n) {
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        int half = dp[i][j] / 2, odd = dp[i][j] % 2;
        dp[i][j + 1] += half + mp[i][j] * odd;
        dp[i + 1][j] += half + !mp[i][j] * odd;
        if (odd)
          mp[i][j] = !mp[i][j];
      }
    saiki(0, 0);
  }
  return 0;
}
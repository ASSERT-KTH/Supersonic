#include <iostream>
#include <cstring>
using namespace std;

int mp[1001][1001], dp[1001][1001];
int h, w, n;

int main() {
  ios_base::sync_with_stdio(false);
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
        dp[i][j + 1] += (dp[i][j] >> 1) + (mp[i][j] & dp[i][j]);
        dp[i + 1][j] += (dp[i][j] >> 1) + ((~mp[i][j]) & dp[i][j]);
        if (dp[i][j] & 1)
          mp[i][j] = !mp[i][j];
      }
    int x = 0, y = 0;
    while (y != h && x != w) {
      int dx[] = {0, 1}, dy[] = {1, 0};
      int d = mp[y][x];
      x += dx[d];
      y += dy[d];
    }
    cout << y + 1 << " " << x + 1 << endl;
  }
  return 0;
}
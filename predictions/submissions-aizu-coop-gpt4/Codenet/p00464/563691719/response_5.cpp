#include <iostream>
#include <vector>
using namespace std;

void saiki(vector<vector<int>>& mp, int h, int w) {
  int x = 0, y = 0;
  int dx[] = {0, 1}, dy[] = {1, 0};
  while(y != h && x != w) {
    x += dx[mp[y][x]];
    y += dy[mp[y][x]];
  }
  cout << y + 1 << " " << x + 1 << endl;
}

int main() {
  while (1) {
    int h, w, n;
    cin >> h >> w >> n;

    if (!h && !w && !n)
      break;

    vector<vector<int>> mp(h, vector<int>(w)), dp(h, vector<int>(w));
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];

    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * dp[i][j] % 2;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * dp[i][j] % 2;
        if (dp[i][j] % 2)
          mp[i][j] = !mp[i][j];
      }
    saiki(mp, h, w);
  }
  return 0;
}
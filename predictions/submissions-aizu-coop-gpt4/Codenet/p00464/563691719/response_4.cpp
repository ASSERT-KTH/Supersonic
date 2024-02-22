#include <iostream>
#include <vector>
using namespace std;

int main() {
  while (1) {
    int h, w, n;
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;

    vector<vector<int>> mp(h, vector<int>(w));
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];

    vector<vector<int>> dp(h+1, vector<int>(w+1, 0));
    dp[0][0] = n - 1;

    bool isOdd = dp[0][0] % 2;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * isOdd;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * isOdd;
        if (isOdd)
          mp[i][j] = !mp[i][j];
        isOdd = !isOdd;
      }

    int x = 0, y = 0;
    while (x < w && y < h) {
      int dx[] = {0, 1}, dy[] = {1, 0};
      int dir = mp[y][x];
      x += dx[dir];
      y += dy[dir];
    }
    cout << y + 1 << " " << x + 1 << endl;
  }
  return 0;
}
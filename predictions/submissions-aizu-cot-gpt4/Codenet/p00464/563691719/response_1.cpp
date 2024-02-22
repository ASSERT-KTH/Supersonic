#include <iostream>
#include <cstring>

int mp[1001][1001], dp[1001][1001];

int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  while (y != h && x != w) {
    int temp = x;
    x = x + dx[mp[y][x]];
    y = y + dy[mp[temp][y]];
  }
  std::cout << y + 1 << " " << x + 1 << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  while (1) {
    std::cin >> h >> w >> n;
    if (!h && !w && !n)
      break;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        std::cin >> mp[i][j];
    std::memset(dp, 0, sizeof(dp));
    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * dp[i][j] % 2;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * dp[i][j] % 2;
        if (dp[i][j] % 2)
          mp[i][j] = !mp[i][j];
      }
    saiki(0, 0);
  }
  return 0;
}
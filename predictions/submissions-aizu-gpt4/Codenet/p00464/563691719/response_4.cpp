#include <iostream>
#include <vector>

int h, w, n;
std::vector<std::vector<int>> mp, dp;

void saiki(int x, int y) {
  static const std::vector<int> dx{0, 1}, dy{1, 0};
  if (y == h || x == w)
    std::cout << y + 1 << " " << x + 1 << '\n';
  else
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}

int main() {
  while (std::cin >> h >> w >> n && (h || w || n)) {
    mp = std::vector<std::vector<int>>(h, std::vector<int>(w));
    dp = std::vector<std::vector<int>>(h, std::vector<int>(w));
    for (auto &row : mp)
      for (auto &cell : row)
        std::cin >> cell;
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
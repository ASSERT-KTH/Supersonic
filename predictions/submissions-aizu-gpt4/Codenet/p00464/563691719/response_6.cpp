#include <iostream>
#include <cstring>

constexpr int SIZE = 1001;
int mp[SIZE][SIZE], dp[SIZE][SIZE];
int h, w, n;

void saiki(int x, int y) {
  static const int dx[] = {0, 1}, dy[] = {1, 0};
  if (y == h || x == w) {
    std::cout << y + 1 << " " << x + 1 << std::endl;
  } else {
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
  }
}

int main() {
  while (std::cin >> h >> w >> n, h || w || n) {
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j)
        std::cin >> mp[i][j];
    std::memset(dp, 0, sizeof(dp));
    dp[0][0] = n - 1;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) {
        int temp = dp[i][j] / 2;
        int mod = dp[i][j] % 2;
        dp[i][j + 1] += temp + mp[i][j] * mod;
        dp[i + 1][j] += temp + !mp[i][j] * mod;
        if (mod)
          mp[i][j] = !mp[i][j];
      }
    saiki(0, 0);
  }
  return 0;
}
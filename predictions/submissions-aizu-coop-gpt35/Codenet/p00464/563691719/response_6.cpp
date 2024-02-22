#include <iostream>
#include <cstring>

bool mp[1001][1001];
int dp[1001][1001];

int h, w, n;

void printCoordinates(int x, int y) {
  int dx[] = {0, 1};
  int dy[] = {1, 0};

  while (y != h && x != w) {
    x += dx[mp[y][x]];
    y += dy[mp[y][x]];
  }

  std::cout << y + 1 << " " << x + 1 << std::endl;
}

int main() {
  while (true) {
    std::cin >> h >> w >> n;

    if (!h && !w && !n)
      break;

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        std::cin >> mp[i][j];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = n - 1;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] = dp[i][j] / 2 + mp[i][j] * dp[i][j] % 2;
        dp[i + 1][j] = dp[i][j] / 2 + !mp[i][j] * dp[i][j] % 2;

        if (dp[i][j] % 2)
          mp[i][j] = !mp[i][j];
      }
    }

    printCoordinates(0, 0);
  }

  return 0;
}
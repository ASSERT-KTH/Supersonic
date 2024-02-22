#include <iostream>
#include <vector>
#include <cstring>

int main() {
  int height, width, num;
  
  while (true) {
    std::cin >> height >> width >> num;
    if (height == 0 && width == 0 && num == 0)
      break;

    std::vector<std::vector<int>> mp(height, std::vector<int>(width));
    std::vector<std::vector<int>> dp(height, std::vector<int>(width, 0));

    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
        std::cin >> mp[i][j];

    dp[0][0] = num - 1;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        int div = dp[i][j] / 2;
        int mod = dp[i][j] % 2;

        dp[i][j + 1] += div + mp[i][j] * mod;
        dp[i + 1][j] += div + !mp[i][j] * mod;

        if (mod)
          mp[i][j] = !mp[i][j];
      }
    }

    std::vector<std::pair<int, int>> path;
    int x = 0, y = 0;
    while (y != height && x != width) {
      path.push_back({y + 1, x + 1});
      int dx[] = {0, 1};
      int dy[] = {1, 0};
      x += dx[mp[y][x]];
      y += dy[mp[y][x]];
    }

    for (const auto& coord : path)
      std::cout << coord.second << " " << coord.first << std::endl;
  }

  return 0;
}
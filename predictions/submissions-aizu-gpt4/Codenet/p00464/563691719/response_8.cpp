#include <iostream>
#include <cstring>
#define MAX_SIZE 1001

int mp[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][MAX_SIZE];
int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  if (y == h || x == w)
    std::cout << y + 1 << " " << x + 1 << '\n';
  else
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}

int main() {
  std::ios_base::sync_with_stdio(false); 
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
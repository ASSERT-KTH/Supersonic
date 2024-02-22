#include <iostream>
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;
void dfs(int y, int x, int& cnt) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  mp[y][x] = ' ';
  cnt++;
  for (int i = 0; i < 4; ++i)
    dfs(y + dy[i], x + dx[i], cnt);
}
int main() {
  while (std::cin >> W >> H, H || W) {
    int cnt = 0;
    int sy, sx;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        std::cin >> mp[i][j];
        if (mp[i][j] == '@') {
          sy = i;
          sx = j;
          mp[i][j] = '.';
        }
      }
    }
    dfs(sy, sx, cnt);
    std::cout << cnt << std::endl;
  }
}
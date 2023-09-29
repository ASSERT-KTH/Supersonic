#include <cstdio>
using namespace std;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};
char mp[20][22];
int H, W;

inline void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  mp[y][x] = ' ';
  for (int i = 0; i < 4; ++i) dfs(y + dy[i], x + dx[i]);
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx, cnt = 0;
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) {
        scanf("\n%c", &mp[i][j]);
        if (mp[i][j] == '@')
          sy = i, sx = j, mp[i][j] = '.';
        else if (mp[i][j] == ' ')
          cnt++;
      }
    dfs(sy, sx);
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}
#include <cstdio>
using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;

int dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W) return 0;
  switch (mp[y][x]) {
    case '#':
    case ' ':
      return 0;
    default:
      mp[y][x] = ' ';
      int count = 1;
      for (int i = 0; i < 4; ++i) count += dfs(y + dy[i], x + dx[i]);
      return count;
  }
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        scanf("\n%c", &mp[i][j]);
        if (mp[i][j] == '@') sy = i, sx = j, mp[i][j] = '.';
      }
    }
    printf("%d\n", dfs(sy, sx));
  }
}
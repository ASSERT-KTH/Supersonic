#include <cstdio>

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(int y, int x, char mp[][22], int H, int W, int& cnt) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  mp[y][x] = ' ';
  cnt++;
  for (int i = 0; i < 4; ++i) {
    dfs(y + dy[i], x + dx[i], mp, H, W, cnt);
  }
}

int main() {
  int W, H;
  while (scanf("%d %d", &W, &H), H || W) {
    char mp[21][22];
    int sy, sx;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        scanf("\n%c", &mp[i][j]);
        if (mp[i][j] == '@') {
          sy = i;
          sx = j;
          mp[i][j] = '.';
        }
      }
    }
    int cnt = 0;
    dfs(sy, sx, mp, H, W, cnt);
    printf("%d\n", cnt);
  }
}
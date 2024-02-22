#include <cstdio>

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(int y, int x, char* mp, int width) {
  if (mp[y * width + x] == '#' || mp[y * width + x] == ' ')
    return;

  mp[y * width + x] = ' ';

  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny >= 0 && ny < H && nx >= 0 && nx < W && mp[ny * width + nx] != ' ')
      dfs(ny, nx, mp, width);
  }
}

int main() {
  int W, H;

  while (scanf("%d %d", &W, &H), H || W) {
    char mp[H][W];
    int sy, sx;
    int cnt = 0;

    for (int i = 0; i < H; ++i) {
      getchar(); // Read newline character
      for (int j = 0; j < W; ++j) {
        scanf("%c", &mp[i][j]);

        if (mp[i][j] == '@') {
          sy = i;
          sx = j;
          mp[i][j] = '.';
        }
      }
    }

    dfs(sy, sx, &mp[0][0], W);

    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (mp[i][j] == ' ')
          cnt++;
      }
    }

    printf("%d\n", cnt);
  }

  return 0;
}
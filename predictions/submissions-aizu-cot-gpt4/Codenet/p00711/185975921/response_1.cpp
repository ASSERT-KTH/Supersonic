#include <cstdio>

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)

char mp[20][22];
int H, W;

void dfs(int y, int x, int& cnt) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
  mp[y][x] = ' ';
  cnt++;
  rep(i, 4) dfs(y + dy[i], x + dx[i], cnt);
}

int main() {
  while (true) {
    scanf("%d %d", &W, &H);
    if (H == 0 && W == 0) break;
    int sy, sx;
    int cnt = 0;
    getchar();  // consume newline
    rep(i, H) rep(j, W) {
      char c = getchar();
      mp[i][j] = c;
      if (c == '@')
        sy = i, sx = j, mp[i][j] = '.';
    }
    dfs(sy, sx, cnt);
    printf("%d\n", cnt);
  }
}
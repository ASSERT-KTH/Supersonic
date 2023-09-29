#include <cstdio>
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
constexpr int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;
void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  mp[y][x] = ' ';
  rep(i, 4) dfs(y + dy[i], x + dx[i]);
}
int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx, cnt = 0;
    getchar();
    rep(i, H) rep(j, W) {
      mp[i][j] = getchar();
      if (mp[i][j] == '@')
        sy = i, sx = j, mp[i][j] = '.';
      if (mp[i][j] == ' ') cnt++;
    }
    dfs(sy, sx);
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
    getchar();
  }
}
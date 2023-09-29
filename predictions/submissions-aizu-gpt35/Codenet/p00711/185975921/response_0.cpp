#include <cstdio>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;
void dfs(int y, int x) {
  if (mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  mp[y][x] = ' ';
  rep(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (ny >= 0 && ny < H && nx >= 0 && nx < W)
      dfs(ny, nx);
  }
}
int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    rep(i, H) rep(j, W) {
      scanf("\n%c", &mp[i][j]);
      if (mp[i][j] == '@')
        sy = i, sx = j, mp[i][j] = '.';
    }
    dfs(sy, sx);
    int cnt = 0;
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}

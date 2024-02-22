#include <cstdio>
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
#define INLINE_DFS(y, x) do { if (mp[y][x] != '#') { mp[y][x] = ' '; INLINE_DFS(y + 1, x); INLINE_DFS(y - 1, x); INLINE_DFS(y, x + 1); INLINE_DFS(y, x - 1); } } while(0)
char mp[22][24];
int H, W;
int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    rep(i, H + 2) rep(j, W + 2) mp[i][j] = '#';
    rep(i, H) rep(j, W) {
      scanf("\n%c", &mp[i + 1][j + 1]);
      if (mp[i + 1][j + 1] == '@')
        sy = i + 1, sx = j + 1, mp[i + 1][j + 1] = '.';
    }
    INLINE_DFS(sy, sx);
    int cnt = 0;
    rep(i, H) rep(j, W) if (mp[i + 1][j + 1] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}
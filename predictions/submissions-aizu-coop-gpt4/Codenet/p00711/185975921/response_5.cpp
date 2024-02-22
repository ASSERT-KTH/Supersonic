#include <cstdio>
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

// Making dfs inline to avoid function call overhead
inline void dfs(int y, int x, int H, int W, char mp[20][22]) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  mp[y][x] = ' ';
  rep(i, 4) dfs(y + dy[i], x + dx[i], H, W, mp);
}

int main() {
  while (true) {
    int H, W, sy, sx, cnt = 0;
    char mp[20][22];
    scanf("%d %d", &W, &H);
    if (H == 0 && W == 0) break;
    rep(i, H) rep(j, W) {
      scanf("\n%c", &mp[i][j]);
      if (mp[i][j] == '@')
        sy = i, sx = j, mp[i][j] = '.';
    }
    dfs(sy, sx, H, W, mp);
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}
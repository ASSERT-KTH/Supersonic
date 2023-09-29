#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
const int MAXH = 20, MAXW = 22;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[MAXH][MAXW];
int H, W;
bool vis[MAXH][MAXW];
void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || vis[y][x])
    return;
  vis[y][x] = true;
  rep(i, 4) dfs(y + dy[i], x + dx[i]);
}
int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    memset(vis, false, sizeof(vis));
    rep(i, H) rep(j, W) {
      scanf("\n%c", &mp[i][j]);
      if (mp[i][j] == '@')
        sy = i, sx = j, vis[i][j] = true;
    }
    dfs(sy, sx);
    int cnt = 0;
    rep(i, H) rep(j, W) if (vis[i][j]) cnt++;
    printf("%d\n", cnt);
  }
}
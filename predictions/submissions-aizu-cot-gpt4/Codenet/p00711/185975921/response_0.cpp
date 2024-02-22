#include <cstdio>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
bool visited[20][22];
int H, W, cnt;
void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || visited[y][x] || mp[y][x] == '#')
    return;
  visited[y][x] = true;
  cnt++;
  rep(i, 4) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (ny >= 0 && ny < H && nx >= 0 && nx < W && mp[ny][nx] != '#' && !visited[ny][nx])
      dfs(ny, nx);
  }
}
int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    rep(i, H) {
      rep(j, W) {
        scanf("\n%c", &mp[i][j]);
        visited[i][j] = false;
        if (mp[i][j] == '@')
          sy = i, sx = j, mp[i][j] = '.';
      }
    }
    cnt = 0;
    dfs(sy, sx);
    printf("%d\n", cnt);
  }
}
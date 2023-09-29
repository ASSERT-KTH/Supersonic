#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
const int MAX_H = 20, MAX_W = 20;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[MAX_H][MAX_W+1];
int H, W;
void dfs(int y, int x) {
  mp[y][x] = ' ';
  rep(i, 4) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny < 0 || ny >= H || nx < 0 || nx >= W || mp[ny][nx] == '#' || mp[ny][nx] == ' ') continue;
    dfs(ny, nx);
  }
}
int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    rep(i, H) {
      scanf("%s", mp[i]);
      rep(j, W) {
        if (mp[i][j] == '@')
          sy = i, sx = j, mp[i][j] = '.';
      }
    }
    dfs(sy, sx);
    int cnt = 0;
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}
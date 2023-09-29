#include <cstdio>
#include <queue>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;
void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
      continue;
    mp[y][x] = ' ';
    rep(i, 4) q.push({y + dy[i], x + dx[i]});
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
    bfs(sy, sx);
    int cnt = 0;
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}
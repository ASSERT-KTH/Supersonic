#include <cstdio>
using namespace std;
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
    int sy, sx;
    char ch;
    rep(i, H) rep(j, W) {
      scanf(" %c", &ch);
      if (ch == '@')
        sy = i, sx = j, mp[i][j] = '.';
      else
        mp[i][j] = ch;
    }
    dfs(sy, sx);
    int cnt = 0;
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}
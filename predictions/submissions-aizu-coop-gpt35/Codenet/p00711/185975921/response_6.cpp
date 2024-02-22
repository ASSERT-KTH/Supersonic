#include <cstdio>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void dfs(char *mp, int y, int x, int H, int W, int& cnt) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y * W + x] == '#' || mp[y * W + x] == ' ')
    return;
  mp[y * W + x] = ' ';
  cnt++;
  rep(i, 4) dfs(mp, y + dy[i], x + dx[i], H, W, cnt);
}

int main() {
  while (true) {
    int W, H;
    scanf("%d %d", &W, &H);
    if (H == 0 && W == 0)
      break;
      
    char *mp = new char[H * W];
    int sy, sx;
    rep(i, H) rep(j, W) {
      scanf("\n%c", &mp[i * W + j]);
      if (mp[i * W + j] == '@')
        sy = i, sx = j, mp[i * W + j] = '.';
    }

    int cnt = 0;
    dfs(mp, sy, sx, H, W, cnt);
    printf("%d\n", cnt);

    delete[] mp;
  }
}
#include <cstdio>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int H, W;

void dfs(int y, int x, char** mp) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
    
  mp[y][x] = ' ';

  rep(i, 4) dfs(y + dy[i], x + dx[i], mp);
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    char** mp = new char*[H];
    rep(i, H) {
      mp[i] = new char[W];
      rep(j, W) {
        scanf("\n%c", &mp[i][j]);
        if (mp[i][j] == '@')
          sy = i, sx = j, mp[i][j] = '.';
      }
    }

    dfs(sy, sx, mp);

    int cnt = 0;
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);

    rep(i, H) delete[] mp[i];
    delete[] mp;
  }
}
#include <cstdio>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W, cnt;

void dfs(int y, int x) {
  // check if the cell is not marked and is within the grid
  if (mp[y][x] == '.') {
    // increment counter and mark the cell
    cnt++;
    mp[y][x] = ' ';

    // call dfs for each direction
    if (y > 0) dfs(y - 1, x);
    if (y < H - 1) dfs(y + 1, x);
    if (x > 0) dfs(y, x - 1);
    if (x < W - 1) dfs(y, x + 1);
  }
}

int main() {
  char ch;
  while (scanf("%d %d", &W, &H), H | W) {
    int sy, sx;
    getchar(); // to consume the newline character
    rep(i, H) rep(j, W) {
      ch = getchar();
      if (ch == '@')
        sy = i, sx = j, mp[i][j] = '.';
      else
        mp[i][j] = ch;
    }
    // initialize counter to 0 before calling dfs
    cnt = 0;
    dfs(sy, sx);
    printf("%d\n", cnt);
  }
}
#include <cstdio>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W, cnt;

void dfs(int y, int x) {
  // Mark the cell as visited
  mp[y][x] = ' ';
  cnt++; // Increment the counter

  // Explore the neighboring cells
  rep(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (ny >= 0 && ny < H && nx >= 0 && nx < W && mp[ny][nx] != '#' && mp[ny][nx] != ' ')
      dfs(ny, nx);
  }
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    cnt = 0; // Reset the counter

    // Read the entire row at once
    rep(i, H) {
      scanf("%s", mp[i]);
      rep(j, W) {
        if (mp[i][j] == '@') {
          sy = i, sx = j, mp[i][j] = '.';
        }
      }
    }

    dfs(sy, sx);
    printf("%d\n", cnt);
  }
}
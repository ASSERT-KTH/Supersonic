#include <cstdio>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool mp[20][20]; // Optimized: Use a 2D array of boolean values
int H, W;

void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || !mp[y][x]) // Optimized: Combined conditions
    return;
  mp[y][x] = false; // Optimized: Use false to represent blocked spaces
  rep(i, 4) dfs(y + dy[i], x + dx[i]);
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    rep(i, H) {
      getchar(); // Read the newline character before each row
      rep(j, W) {
        char c;
        scanf("%c", &c);
        mp[i][j] = (c == '@' || c == '.'); // Optimized: Store only true for empty spaces
        if (c == '@')
          sy = i, sx = j;
      }
    }
    dfs(sy, sx);
    int cnt = 0;
    rep(i, H) rep(j, W) cnt += !mp[i][j]; // Optimized: Count empty spaces while performing DFS
    printf("%d\n", cnt);
  }
}
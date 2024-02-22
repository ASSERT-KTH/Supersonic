#include <cstdio>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)

// Use a linear array to represent the map
char mp[440];
int H, W;

// Use a linear formula to access elements in the map
int getIndex(int y, int x) {
  return y * W + x;
}

void dfs(int y, int x) {
  if (mp[getIndex(y, x)] == '#' || mp[getIndex(y, x)] == ' ')
    return;

  mp[getIndex(y, x)] = ' ';
  
  // Unroll the loop manually
  if (y > 0) dfs(y - 1, x);
  if (y < H - 1) dfs(y + 1, x);
  if (x > 0) dfs(y, x - 1);
  if (x < W - 1) dfs(y, x + 1);
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    rep(i, H) {
      rep(j, W) {
        scanf("\n%c", &mp[getIndex(i, j)]);
        if (mp[getIndex(i, j)] == '@') {
          sy = i;
          sx = j;
          mp[getIndex(i, j)] = '.';
        }
      }
    }

    dfs(sy, sx);

    int cnt = 0;
    rep(i, H) {
      rep(j, W) {
        if (mp[getIndex(i, j)] == ' ') {
          cnt++;
        }
      }
    }

    printf("%d\n", cnt);
  }
}
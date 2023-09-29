#include <cstdio>
using namespace std;

constexpr int MAX_SIZE = 22;
constexpr int DIRECTIONS = 4;

char mp[MAX_SIZE][MAX_SIZE];
int dx[DIRECTIONS] = {-1, 1, 0, 0}, dy[DIRECTIONS] = {0, 0, -1, 1};
int H, W;

inline void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  mp[y][x] = ' ';
  for (int i = 0; i < DIRECTIONS; ++i) dfs(y + dy[i], x + dx[i]);
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx, cnt = 0;
    for(int i = 0; i < H; ++i) {
      for(int j = 0; j < W; ++j) {
        scanf(" %c", &mp[i][j]);
        if (mp[i][j] == '@') sy = i, sx = j, mp[i][j] = '.';
      }
    }
    dfs(sy, sx);
    for(int i = 0; i < H; ++i) {
      for(int j = 0; j < W; ++j) {
        if (mp[i][j] == ' ') ++cnt;
      }
    }
    printf("%d\n", cnt);
  }
}
#include <cstdio>
using namespace std;

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;

void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
    return;
  mp[y][x] = ' ';
  for(int i = 0; i < 4; i++) dfs(y + dy[i], x + dx[i]);
}

int main() {
  int cnt = 0;
  while (fscanf(stdin, "%d %d", &W, &H), H || W) {
    int sy, sx;
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        fscanf(stdin, "\n%c", &mp[i][j]);
        if (mp[i][j] == '@') {
          sy = i, sx = j, mp[i][j] = '.';
        }
      }
    }
    dfs(sy, sx);
    cnt = 0;
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        if (mp[i][j] == ' ') cnt++;
      }
    }
    fprintf(stdout, "%d\n", cnt);
  }
  return 0;
}
#include <iostream>
using namespace std;

const int MAX_H = 20;
const int MAX_W = 22;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char mp[MAX_H][MAX_W];
int H, W;

void dfs(int& y, int& x, int& cnt) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '.' || mp[y][x] == '#')
    return;

  mp[y][x] = '.';
  cnt++;

  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    dfs(ny, nx, cnt);
  }
}

int main() {
  while (cin >> W >> H, H || W) {
    int sy, sx;
    int cnt = 0;

    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        cin >> mp[i][j];

        if (mp[i][j] == '@') {
          sy = i;
          sx = j;
          mp[i][j] = '.';
        }
      }
    }

    dfs(sy, sx, cnt);
    cout << cnt << endl;
  }
  return 0;
}
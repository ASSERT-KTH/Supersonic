#include <iostream>
using namespace std;

const int MAX_H = 20;
const int MAX_W = 20;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char mp[MAX_H][MAX_W];
int H, W;

void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] != '.') {
    return;
  }
  mp[y][x] = ' ';
  for (int i = 0; i < 4; ++i) {
    dfs(y + dy[i], x + dx[i]);
  }
}

int main() {
  while (cin >> W >> H, H || W) {
    int sy, sx;
    for (unsigned int i = 0; i < H; ++i) {
      for (unsigned int j = 0; j < W; ++j) {
        cin >> mp[i][j];
        if (mp[i][j] == '@') {
          sy = i;
          sx = j;
          mp[i][j] = '.';
        }
      }
    }
    dfs(sy, sx);
    int totalCells = H * W;
    int visitedCells = 0;
    for (unsigned int i = 0; i < H; ++i) {
      for (unsigned int j = 0; j < W; ++j) {
        if (mp[i][j] != ' ') {
          visitedCells++;
        }
      }
    }
    int cnt = totalCells - visitedCells;
    cout << cnt << endl;
  }
  return 0;
}
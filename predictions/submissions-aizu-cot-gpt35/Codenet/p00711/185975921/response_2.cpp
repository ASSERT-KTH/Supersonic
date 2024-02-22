#include <iostream>
#include <cstring>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(char** mp, int y, int x, int H, int W, int& cnt) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] != '.') {
    return;
  }
  mp[y][x] = ' ';
  cnt++;
  for (int i = 0; i < 4; ++i) {
    dfs(mp, y + dy[i], x + dx[i], H, W, cnt);
  }
}

int main() {
  int W, H;
  while (cin >> W >> H, H || W) {
    char** mp = new char*[H];
    for (int i = 0; i < H; ++i) {
      mp[i] = new char[W + 1];
      cin >> mp[i];
    }
    int sy, sx, cnt = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (mp[i][j] == '@') {
          sy = i;
          sx = j;
          mp[i][j] = '.';
        }
      }
    }
    dfs(mp, sy, sx, H, W, cnt);
    cout << cnt << endl;

    for (int i = 0; i < H; ++i) {
      delete[] mp[i];
    }
    delete[] mp;
  }
}
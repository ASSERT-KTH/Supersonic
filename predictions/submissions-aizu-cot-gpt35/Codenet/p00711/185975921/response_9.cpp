#include <iostream>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char mp[440];
int H, W;

void dfs(int y, int x) {
  if (y < 0 || y >= H || x < 0 || x >= W || mp[y * W + x] == '#' || mp[y * W + x] == ' ')
    return;
  mp[y * W + x] = ' ';
  for (int i = 0; i < 4; ++i) {
    dfs(y + dy[i], x + dx[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> W >> H, H || W) {
    int sy, sx;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        cin >> mp[i * W + j];
        if (mp[i * W + j] == '@') {
          sy = i;
          sx = j;
          mp[i * W + j] = '.';
        }
      }
    }

    dfs(sy, sx);

    int cnt = 0;
    for (int i = 0; i < H * W; ++i) {
      if (mp[i] == ' ') {
        cnt++;
      }
    }

    cout << cnt << "\n";
  }

  return 0;
}
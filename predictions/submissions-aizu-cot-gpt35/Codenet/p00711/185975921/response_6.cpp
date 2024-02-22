#include <iostream>
#include <stack>
using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;

void dfs(int sy, int sx) {
  stack<pair<int, int>> st;
  st.push({sy, sx});

  while (!st.empty()) {
    int y = st.top().first;
    int x = st.top().second;
    st.pop();

    if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
      continue;

    mp[y][x] = ' ';

    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny >= 0 && ny < H && nx >= 0 && nx < W && mp[ny][nx] != '#' && mp[ny][nx] != ' ')
        st.push({ny, nx});
    }
  }
}

int main() {
  while (cin >> W >> H, H || W) {
    int sy, sx;
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

    dfs(sy, sx);

    int cnt = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (mp[i][j] == ' ')
          cnt++;
      }
    }

    cout << cnt << endl;
  }

  return 0;
}
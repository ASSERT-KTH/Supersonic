#include <cstdio>
#include <stack>

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int main() {
  int H, W;
  while (scanf("%d %d", &W, &H), H || W) {
    char** mp = new char*[H];
    for (int i = 0; i < H; ++i) {
      mp[i] = new char[W];
      for (int j = 0; j < W; ++j) {
        scanf("\n%c", &mp[i][j]);
        if (mp[i][j] == '@')
          mp[i][j] = '.';
      }
    }

    int sy, sx;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (mp[i][j] == '.') {
          sy = i, sx = j;
          break;
        }
      }
    }

    std::stack<std::pair<int, int>> st;
    st.push({sy, sx});
    int cnt = 0;
    while (!st.empty()) {
      int y = st.top().first;
      int x = st.top().second;
      st.pop();
      if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
        continue;
      mp[y][x] = ' ';
      cnt++;
      for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        st.push({ny, nx});
      }
    }

    printf("%d\n", cnt);

    for (int i = 0; i < H; ++i) {
      delete[] mp[i];
    }
    delete[] mp;
  }
  
  return 0;
}
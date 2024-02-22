#include <cstdio>
#include <stack>
using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char** mp;
int H, W;

void dfs(int y, int x) {
  stack<pair<int, int>> st;
  st.push({y, x});

  while (!st.empty()) {
    auto [y, x] = st.top();
    st.pop();

    if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
      continue;

    mp[y][x] = ' ';
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny >= 0 && ny < H && nx >= 0 && nx < W && mp[ny][nx] != '#' && mp[ny][nx] != ' ')
        st.push({ny, nx});
    }
  }
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    mp = new char*[H];
    for (int i = 0; i < H; i++) {
      mp[i] = new char[W];
      for (int j = 0; j < W; j++) {
        scanf("\n%c", &mp[i][j]);
        if (mp[i][j] == '@') {
          mp[i][j] = '.';
          dfs(i, j);
        }
      }
    }
    
    int cnt = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (mp[i][j] == ' ')
          cnt++;
      }
      delete[] mp[i];
    }
    delete[] mp;
    
    printf("%d\n", cnt);
  }
}
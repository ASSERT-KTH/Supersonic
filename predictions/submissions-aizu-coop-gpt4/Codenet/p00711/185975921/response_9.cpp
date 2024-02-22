#include <cstdio>
#include <stack>
using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;

void dfs(int y, int x) {
  int cnt = 0;
  stack<pair<int, int>> stk;
  stk.push({y, x});
  while (!stk.empty()) {
    pair<int, int> top = stk.top();
    stk.pop();
    for (int i = 0; i < 4; ++i) {
      int ny = top.first + dy[i], nx = top.second + dx[i];
      if (mp[ny][nx] != '#' && mp[ny][nx] != ' ') {
        mp[ny][nx] = ' ';
        stk.push({ny, nx});
        ++cnt;
      }
    }
  }
  printf("%d\n", cnt);
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    for (int i = 0; i < H; ++i)
      for (int j = 0; j < W; ++j) {
        scanf("\n%c", &mp[i][j]);
        if (mp[i][j] == '@')
          sy = i, sx = j, mp[i][j] = '.';
      }
    dfs(sy, sx);
  }
}
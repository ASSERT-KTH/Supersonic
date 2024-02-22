#include <cstdio>
#include <stack>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;

void dfs(int y, int x) {
  stack<pair<int, int>> stk;
  stk.push({y, x});

  while (!stk.empty()) {
    int cy = stk.top().first;
    int cx = stk.top().second;
    stk.pop();

    if (cy < 0 || cy >= H || cx < 0 || cx >= W || mp[cy][cx] == '#' || mp[cy][cx] == ' ')
      continue;

    mp[cy][cx] = ' ';

    rep(i, 4) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      stk.push({ny, nx});
    }
  }
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    rep(i, H) rep(j, W) {
      getchar_unlocked(); // consume newline character
      char c = getchar_unlocked();
      mp[i][j] = c;
      if (c == '@')
        sy = i, sx = j, mp[i][j] = '.';
    }
    dfs(sy, sx);
    int cnt = 0;
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}
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
    auto [cy, cx] = stk.top();
    stk.pop();
    if (cy < 0 || cy >= H || cx < 0 || cx >= W || mp[cy][cx] == '#' || mp[cy][cx] == ' ')
      continue;
    mp[cy][cx] = ' ';
    rep(i, 4) stk.push({cy + dy[i], cx + dx[i]});
  }
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx, cnt = 0;
    rep(i, H) rep(j, W) {
      scanf("\n%c", &mp[i][j]);
      if (mp[i][j] == '@')
        sy = i, sx = j, mp[i][j] = '.';
      if (mp[i][j] == ' ') cnt++;
    }
    dfs(sy, sx);
    rep(i, H) rep(j, W) if (mp[i][j] == ' ') cnt++;
    printf("%d\n", cnt);
  }
}
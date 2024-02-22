#include <cstdio>
#include <stack>
using namespace std;
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[20][22];
int H, W;

void dfs(int y, int x, int& cnt) {
  stack<pair<int, int>> stk;
  stk.push({y, x});
  
  while (!stk.empty()) {
    pair<int, int> top = stk.top();
    stk.pop();
    
    if (top.first < 0 || top.first >= H || top.second < 0 || top.second >= W || mp[top.first][top.second] == '#' || mp[top.first][top.second] == ' ')
      continue;
      
    mp[top.first][top.second] = ' ';
    cnt++;
      
    rep(i, 4) stk.push({top.first + dy[i], top.second + dx[i]});
  }
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx, cnt = 0;
    rep(i, H) rep(j, W) {
      scanf("\n%c", &mp[i][j]);
      if (mp[i][j] == '@')
        sy = i, sx = j, mp[i][j] = '.';
    }
    dfs(sy, sx, cnt);
    printf("%d\n", cnt);
  }
}
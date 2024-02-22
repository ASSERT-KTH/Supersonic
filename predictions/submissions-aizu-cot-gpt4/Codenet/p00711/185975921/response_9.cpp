#include <iostream>
#include <stack>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char mp[22][24]; // Extra space for the wall
int H, W;

void dfs(int y, int x, int& cnt) {
  stack<pair<int, int>> stk;
  stk.push({y, x});

  while (!stk.empty()) {
    auto [y, x] = stk.top();
    stk.pop();
    if (mp[y][x] == '.')
        ++cnt;
    mp[y][x] = ' ';

    rep(i, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (mp[ny][nx] == '.')
        stk.push({ny, nx});
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  while (cin >> W >> H, H || W) {
    int sy, sx, cnt = 0;
    rep(i, H + 2) fill(mp[i], mp[i] + W + 2, '#'); // Add wall
    
    rep(i, H) rep(j, W) {
      char& c = mp[i + 1][j + 1];
      cin >> c;
      if (c == '@')
        sy = i + 1, sx = j + 1, c = '.';
    }

    dfs(sy, sx, cnt);
    cout << cnt << '\n';
  }
}
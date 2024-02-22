#include <cstdio>
#include <stack>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool visited[20][20];
int H, W;

void dfs(int sy, int sx) {
  stack<pair<int, int>> st;
  st.push({sy, sx});

  while (!st.empty()) {
    int y = st.top().first;
    int x = st.top().second;
    st.pop();

    if (y < 0 || y >= H || x < 0 || x >= W || visited[y][x]) {
      continue;
    }

    visited[y][x] = true;

    // Check adjacent cells
    if (y - 1 >= 0 && !visited[y - 1][x]) {
      st.push({y - 1, x});
    }
    if (y + 1 < H && !visited[y + 1][x]) {
      st.push({y + 1, x});
    }
    if (x - 1 >= 0 && !visited[y][x - 1]) {
      st.push({y, x - 1});
    }
    if (x + 1 < W && !visited[y][x + 1]) {
      st.push({y, x + 1});
    }
  }
}

int main() {
  while (scanf("%d %d", &W, &H), H || W) {
    int sy, sx;
    rep(i, H) rep(j, W) {
      char c;
      scanf("\n%c", &c);
      visited[i][j] = false;
      if (c == '@') {
        sy = i, sx = j;
      }
    }

    dfs(sy, sx);

    int cnt = 0;
    rep(i, H) rep(j, W) {
      if (visited[i][j]) {
        cnt++;
      }
    }

    printf("%d\n", cnt);
  }

  return 0;
}
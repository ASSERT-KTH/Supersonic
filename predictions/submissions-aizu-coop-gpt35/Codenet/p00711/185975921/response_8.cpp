#include <cstdio>
#include <stack>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char** mp;
bool** visited;
int H, W;

void dfs(int sy, int sx) {
  stack<pair<int, int>> st;
  st.push({sy, sx});
  visited[sy][sx] = true;

  while (!st.empty()) {
    int y = st.top().first;
    int x = st.top().second;
    st.pop();

    rep(i, 4) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny >= 0 && ny < H && nx >= 0 && nx < W && !visited[ny][nx] &&
          mp[ny][nx] != '#' && mp[ny][nx] != ' ') {
        st.push({ny, nx});
        visited[ny][nx] = true;
      }
    }
  }
}

int main() {
  while (scanf("%d %d", &W, &H) == 2 && H != 0 && W != 0) {
    mp = new char*[H];
    visited = new bool*[H];
    rep(i, H) {
      mp[i] = new char[W];
      visited[i] = new bool[W];
      rep(j, W) {
        scanf("\n%c", &mp[i][j]);
        if (mp[i][j] == '@') {
          dfs(i, j);
          mp[i][j] = '.';
        }
        visited[i][j] = false;
      }
    }

    int cnt = 0;
    rep(i, H) {
      rep(j, W) {
        if (visited[i][j]) {
          cnt++;
        }
      }
    }

    printf("%d\n", cnt);

    rep(i, H) {
      delete[] mp[i];
      delete[] visited[i];
    }
    delete[] mp;
    delete[] visited;
  }
}
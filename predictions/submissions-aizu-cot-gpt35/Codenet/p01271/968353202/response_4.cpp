#include <iostream>
#include <queue>
using namespace std;

int w, h;
char mp[2][51][51];
bool visited[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs(int lx, int ly, int rx, int ry) {
  queue<pair<int, int>> Q;
  Q.push({lx, ly});
  visited[lx][ly] = true;

  while (!Q.empty()) {
    auto t = Q.front();
    Q.pop();

    int cnt = (mp[0][t.first][t.second] == '%') + (mp[1][t.first][t.second] == '%');
    if (cnt == 2)
      return true;

    for (int i = 0; i < 4; i++) {
      int nlx = t.first + dx[i], nly = t.second + dy[i];
      int nrx = rx - dx[i], nry = ry + dy[i];

      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nlx][nly] == '#')
        continue;
      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nrx][nry] == '#')
        continue;

      if (!visited[nlx][nly]) {
        visited[nlx][nly] = true;
        Q.push({nlx, nly});
      }
    }
  }

  return false;
}

int main() {
  while (1) {
    cin >> w >> h;
    if (!w && !h)
      break;

    for (int i = 0; i < h; i++)
      cin >> mp[0][i] >> mp[1][i];

    int lx, ly, rx, ry;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L')
          lx = i, ly = j;
        if (mp[1][i][j] == 'R')
          rx = i, ry = j;
      }

    memset(visited, false, sizeof(visited));
    if (bfs(lx, ly, rx, ry))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
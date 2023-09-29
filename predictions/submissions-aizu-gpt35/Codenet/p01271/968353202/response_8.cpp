#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_H = 51;
const int MAX_W = 51;

int w, h;
char mp[2][MAX_H][MAX_W+1];
bool visited[MAX_H][MAX_W][MAX_H][MAX_W];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct po {
  int lx, ly, rx, ry;
};

bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push({lx, ly, rx, ry});
  visited[ly][lx][ry][rx] = true;

  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();

    int cnt = (mp[0][t.ly][t.lx] == '%') + (mp[1][t.ry][t.rx] == '%');
    if (cnt == 2)
      return true;

    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.lx + dx[i], nly = t.ly + dy[i];
      int nrx = t.rx - dx[i], nry = t.ry + dy[i];

      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#') {
        nlx = t.lx;
        nly = t.ly;
        flg++;
      }

      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#') {
        nrx = t.rx;
        nry = t.ry;
        flg++;
      }

      if (flg == 2 || visited[nly][nlx][nry][nrx])
        continue;

      visited[nly][nlx][nry][nrx] = true;
      Q.push({nlx, nly, nrx, nry});
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (1) {
    cin >> w >> h;

    if (!w && !h)
      break;

    for (int i = 0; i < h; ++i)
      for (int j = 0; j < 2*w; ++j)
        cin >> mp[j/w][i][j%w];

    int lx, ly, rx, ry;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) {
        if (mp[0][i][j] == 'L') {
          lx = j;
          ly = i;
        }
        if (mp[1][i][j] == 'R') {
          rx = j;
          ry = i;
        }
      }

    memset(visited, 0, sizeof(visited));

    if (bfs(lx, ly, rx, ry))
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
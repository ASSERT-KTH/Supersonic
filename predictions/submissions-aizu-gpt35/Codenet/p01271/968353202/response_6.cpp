#include <cstring>
#include <iostream>
#include <queue>
#include <tuple> // new include
using namespace std;

// changed struct to tuple
using po = tuple<int, int, int, int>;

int w, h;
string mp[2][51];
bool visited[51][51][51][51];

// changed function to return bool
bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push(make_tuple(lx, ly, rx, ry));
  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();
    int cnt = (mp[0][get<1>(t)][get<0>(t)] == '%') + (mp[1][get<3>(t)][get<2>(t)] == '%');
    if (cnt == 2)
      return true;
    if (visited[get<0>(t)][get<1>(t)][get<2>(t)][get<3>(t)] || cnt == 1)
      continue;
    visited[get<0>(t)][get<1>(t)][get<2>(t)][get<3>(t)] = 1;
    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = get<0>(t) + dx[i], nly = get<1>(t) + dy[i];
      int nrx = get<2>(t) - dx[i], nry = get<3>(t) + dy[i];
      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#')
        nlx = get<0>(t), nly = get<1>(t), flg++;
      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#')
        nrx = get<2>(t), nry = get<3>(t), flg++;
      if (flg == 2)
        continue;
      Q.push(make_tuple(nlx, nly, nrx, nry));
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
          lx = j, ly = i;
        if (mp[1][i][j] == 'R')
          rx = j, ry = i;
      }
    memset(visited, 0, sizeof(visited));
    if (bfs(lx, ly, rx, ry))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
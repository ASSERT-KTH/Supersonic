#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct po {
  int lx, ly, rx, ry;
};
int w, h;
vector<pair<int, int>> L, R, P;
bool visited[51][51][51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push((po){lx, ly, rx, ry});
  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();
    int cnt = (P.count(make_pair(t.lx, t.ly)) > 0) + (P.count(make_pair(t.rx, t.ry)) > 0);
    if (cnt == 2)
      return true;
    if (visited[t.lx][t.ly][t.rx][t.ry] || cnt == 1)
      continue;
    visited[t.lx][t.ly][t.rx][t.ry] = 1;
    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.lx + dx[i], nly = t.ly + dy[i];
      int nrx = t.rx - dx[i], nry = t.ry - dy[i];
      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || P.count(make_pair(nlx, nly)) == 0)
        nlx = t.lx, nly = t.ly, flg++;
      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || P.count(make_pair(nrx, nry)) == 0)
        nrx = t.rx, nry = t.ry, flg++;
      if (flg == 2)
        continue;
      Q.push((po){nlx, nly, nrx, nry});
    }
  }
  return false;
}
int main() {
  while (1) {
    cin >> w >> h;
    if (!w && !h)
      break;
    string line;
    for (int i = 0; i < h; i++) {
      cin >> line;
      for (int j = 0; j < w; j++) {
        if (line[j] == 'L')
          L.push_back(make_pair(j, i));
        else if (line[j] == 'R')
          R.push_back(make_pair(j, i));
        else if (line[j] == '%')
          P.push_back(make_pair(j, i));
      }
    }
    memset(visited, 0, sizeof(visited));
    if (bfs(L[0].first, L[0].second, R[0].first, R[0].second))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    L.clear(); R.clear(); P.clear();
  }
  return 0;
}
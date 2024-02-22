#include <unordered_set>
#include <iostream>
#include <queue>
using namespace std;
struct po {
  int lx, ly, rx, ry;
};
int w, h;
string mp[2][51];
unordered_set<string> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string encode(int lx, int ly, int rx, int ry) {
  return to_string(lx) + "_" + to_string(ly) + "_" + to_string(rx) + "_" + to_string(ry);
}
bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push((po){lx, ly, rx, ry});
  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();
    int cnt = (mp[0][t.ly][t.lx] == '%') + (mp[1][t.ry][t.rx] == '%');
    if (cnt == 2)
      return true;
    string key = encode(t.lx, t.ly, t.rx, t.ry);
    if (visited.count(key) > 0 || cnt == 1)
      continue;
    visited.insert(key);
    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.lx + dx[i], nly = t.ly + dy[i];
      int nrx = t.rx - dx[i], nry = t.ry + dy[i];
      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#')
        nlx = t.lx, nly = t.ly, flg++;
      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#')
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
    for (int i = 0; i < h; i++)
      cin >> mp[0][i] >> mp[1][i];
    int lx, ly, rx, ry;
    bool foundL = false, foundR = false;
    for (int i = 0; i < h && !(foundL && foundR); i++)
      for (int j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L') {
          lx = j, ly = i;
          foundL = true;
        }
        if (mp[1][i][j] == 'R') {
          rx = j, ry = i;
          foundR = true;
        }
      }
    visited.clear();
    if (bfs(lx, ly, rx, ry))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
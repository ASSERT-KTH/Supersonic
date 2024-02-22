#include <iostream>
#include <queue>
#include <cstring>

struct po {
  int lx, ly, rx, ry;
};

int w, h;
std::string mp[2][51];
bool visited[51][51][51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs(po& start) {
  std::queue<po> Q;
  Q.push(start);
  
  bool left_reached = false;
  bool right_reached = false;

  while (!Q.empty()) {
    po& t = Q.front();
    Q.pop();
    
    if (left_reached && right_reached)
      return true;

    if (visited[t.lx][t.ly][t.rx][t.ry])
      continue;
    
    visited[t.lx][t.ly][t.rx][t.ry] = true;
    
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
      
      if (flg == 2)
        continue;
      
      Q.push((po){nlx, nly, nrx, nry});
    }
  }

  return false;
}

int main() {
  while (true) {
    std::cin >> w >> h;
    if (!w && !h)
      break;

    for (int i = 0; i < h; i++)
      std::cin >> mp[0][i] >> mp[1][i];
    
    po start;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L') {
          start.lx = j;
          start.ly = i;
        }
        if (mp[1][i][j] == 'R') {
          start.rx = j;
          start.ry = i;
        }
      }
    }
    
    memset(visited, 0, sizeof(visited));
    
    if (bfs(start))
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }
  
  return 0;
}
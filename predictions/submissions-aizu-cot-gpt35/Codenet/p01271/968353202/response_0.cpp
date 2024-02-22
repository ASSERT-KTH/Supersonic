#include <iostream>
#include <queue>
using namespace std;

int w, h;
char mp[2][51][51];

bool bfs(int lx, int ly, int rx, int ry) {
  queue<int> Q;
  Q.push(lx);
  Q.push(ly);
  Q.push(rx);
  Q.push(ry);
  
  while (!Q.empty()) {
    int t_lx = Q.front(); Q.pop();
    int t_ly = Q.front(); Q.pop();
    int t_rx = Q.front(); Q.pop();
    int t_ry = Q.front(); Q.pop();
    
    if (mp[0][t_ly][t_lx] == '%' && mp[1][t_ry][t_rx] == '%') {
      return true;
    }
    
    if (mp[0][t_ly][t_lx] == '*' || mp[1][t_ry][t_rx] == '*') {
      continue;
    }
    
    mp[0][t_ly][t_lx] = '*';
    mp[1][t_ry][t_rx] = '*';
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    for (int i = 0; i < 4; i++) {
      int nlx = t_lx + dx[i];
      int nly = t_ly + dy[i];
      int nrx = t_rx - dx[i];
      int nry = t_ry + dy[i];
      
      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#') {
        nlx = t_lx;
        nly = t_ly;
      }
      
      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#') {
        nrx = t_rx;
        nry = t_ry;
      }
      
      Q.push(nlx);
      Q.push(nly);
      Q.push(nrx);
      Q.push(nry);
    }
  }
  
  return false;
}

int main() {
  while (1) {
    cin >> w >> h;
    if (!w && !h)
      break;
      
    for (int i = 0; i < h; i++) {
      cin >> mp[0][i] >> mp[1][i];
    }
    
    int lx, ly, rx, ry;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L') {
          lx = j;
          ly = i;
        }
        
        if (mp[1][i][j] == 'R') {
          rx = j;
          ry = i;
        }
      }
    }
    
    if (bfs(lx, ly, rx, ry))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  
  return 0;
}
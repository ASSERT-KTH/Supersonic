#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int W, H, sx, sy, gx, gy;
int csize, wsize;
std::vector<int> wx, wy, cx, cy;
std::vector<std::string> field;
std::map<std::tuple<int, int, int, int, int, int, int, int>, int> DP;

struct state {
  int x, y;
  std::vector<int> cx, cy;
  int Sc;
  
  state(int _x, int _y, const std::vector<int>& _cx, const std::vector<int>& _cy, int _Sc) {
    x = _x;
    y = _y;
    cx = _cx;
    cy = _cy;
    Sc = _Sc;
  }
  
  bool operator<(const state& a) const {
    if (x != a.x) return x < a.x;
    if (y != a.y) return y < a.y;
    if (cx != a.cx) return cx < a.cx;
    if (cy != a.cy) return cy < a.cy;
    return Sc < a.Sc;
  }
  
  bool operator==(const state& a) const {
    return (x == a.x && y == a.y && cx == a.cx && cy == a.cy && Sc == a.Sc);
  }
};

bool isdel(int tx, int ty, const std::vector<int>& ncx, const std::vector<int>& ncy) {
  if (field[ty][tx] != 'w') return true;
  for (int i = 0; i < csize; i++) {
    if (ncx[i] == tx && ncy[i] == ty) return true;
  }
  return false;
}

bool iscontena(int tx, int ty, const std::vector<int>& ncx, const std::vector<int>& ncy, int Sc) {
  for (int i = 0; i < csize; i++) {
    if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i))) return true;
  }
  return false;
}

void BFS(int nx, int ny, const std::vector<int>& ncx, const std::vector<int>& ncy, int Sc, std::vector<std::vector<int>>& bfscost) {
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(nx, ny));
  bfscost[ny][nx] = 0;
  
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    int cost = bfscost[y][x];
    q.pop();
    
    for (int k = 0; k < 4; k++) {
      int tx = x + dx[k];
      int ty = y + dy[k];
      
      if (field[ty][tx] == '#' || bfscost[ty][tx] != -1 || iscontena(tx, ty, ncx, ncy, Sc)) {
        continue;
      }
      
      if (field[ty][tx] == 'w' && !isdel(tx, ty, ncx, ncy)) {
        continue;
      }
      
      bfscost[ty][tx] = cost + 1;
      q.push(std::make_pair(tx, ty));
    }
  }
}

void input() {
  field.clear();
  cx.clear();
  cy.clear();
  wx.clear();
  wy.clear();
  
  for (int i = 0; i < H; i++) {
    std::string row;
    std::cin >> row;
    field.push_back(row);
    
    for (int j = 0; j < W; j++) {
      if (field[i][j] == '@') {
        sx = j;
        sy = i;
      }
      if (field[i][j] == 'E') {
        gx = j;
        gy = i;
      }
      if (field[i][j] == 'w') {
        wx.push_back(j);
        wy.push_back(i);
        wsize++;
      }
      if (field[i][j] == 'c') {
        cx.push_back(j);
        cy.push_back(i);
        csize++;
      }
    }
  }
}

int main() {
  while (std::cin >> H >> W && (H != 0 || W != 0)) {
    csize = wsize = 0;
    DP.clear();
    input();
    int res = INT_MAX;
    std::priority_queue<std::pair<int, state>, std::vector<std::pair<int, state>>, std::greater<std::pair<int, state>>> q;
    q.push(std::make_pair(0, state(sx, sy, cx, cy, 0)));
    DP[std::make_tuple(cx[0], cy[0], cx[1], cy[1], cx[2], cy[2], sx, sy)] = 0;
    
    std::vector<std::vector<int>> bfscost(H, std::vector<int>(W, -1));
    
    while (!q.empty()) {
      int cost = q.top().first;
      int nx = q.top().second.x;
      int ny = q.top().second.y;
      int tSc = q.top().second.Sc;
      std::vector<int> ncx = q.top().second.cx;
      std::vector<int> ncy = q.top().second.cy;
      q.pop();
      
      if (res <= cost) break;
      
      BFS(nx, ny, ncx, ncy, tSc, bfscost);
      
      if (bfscost[gy][gx] != -1) {
        res = std::min(res, cost + bfscost[gy][gx]);
      }
      
      for (int i = 0; i < csize; i++) {
        if (!(tSc & (1 << i))) {
          for (int j = 0; j < 4; j++) {
            int tx = ncx[i] + dx[j];
            int ty = ncy[i] + dy[j];
            
            if (bfscost[ty][tx] == -1) continue;
            
            int ttSc = tSc;
            int dir = (j + 2) % 4;
            int tcx = ncx[i], tcy = ncy[i];
            
            for (;;) {
              int ay = tcy + dy[dir];
              int ax = tcx + dx[dir];
              
              if (field[ay][ax] == '#' || iscontena(ax, ay, ncx, ncy, tSc)) break;
              
              tcx += dx[dir];
              tcy += dy[dir];
              
              if (field[ay][ax] == 'w' && !isdel(ax, ay, ncx, ncy)) {
                ttSc |= 1 << i;
                break;
              }
            }
            
            if (tcx == ncx[i] && tcy == ncy[i]) continue;
            
            std::vector<int> ttcx = ncx;
            std::vector<int> ttcy = ncy;
            ttcx[i] = tcx;
            ttcy[i] = tcy;
            
            int* dpp = &DP[std::make_tuple(ttcx[0], ttcy[0], ttcx[1], ttcy[1], ttcx[2], ttcy[2], tx, ty)];
            
            if (*dpp == -1 || *dpp > cost + bfscost[ty][tx]) {
              *dpp = cost + bfscost[ty][tx];
              q.push(std::make_pair(cost + bfscost[ty][tx], state(tx, ty, ttcx, ttcy, ttSc)));
            }
          }
        }
      }
    }
    
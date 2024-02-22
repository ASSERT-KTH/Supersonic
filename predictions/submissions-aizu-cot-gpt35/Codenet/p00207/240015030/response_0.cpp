#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<int>>& board, int c, int x, int y, int xg, int yg) {
  int w = board[0].size();
  int h = board.size();
  
  if (x < 0 || x >= w || y < 0 || y >= h) {
    return false;
  }
  
  if (board[y][x] != c) {
    return false;
  }
  
  if (x == xg && y == yg) {
    return true;
  }
  
  board[y][x] = 0;
  
  if (DFS(board, c, x + 1, y, xg, yg)) {
    return true;
  }
  
  if (DFS(board, c, x, y + 1, xg, yg)) {
    return true;
  }
  
  if (DFS(board, c, x - 1, y, xg, yg)) {
    return true;
  }
  
  if (DFS(board, c, x, y - 1, xg, yg)) {
    return true;
  }
  
  return false;
}

int main() {
  int w, h;
  
  while (true) {
    cin >> w >> h;
    
    if (w == 0 && h == 0) {
      break;
    }
    
    vector<vector<int>> board(h, vector<int>(w, -1));
    
    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    
    int n, c, d, x, y;
    cin >> n;
    
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      
      for (int i = y; i < y + hb; i++) {
        for (int j = x; j < x + wb; j++) {
          board[i][j] = c;
        }
      }
    }
    
    if (DFS(board, board[ys][xs], xs, ys, xg, yg)) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  }
  
  return 0;
}
#include <iostream>

bool DFS(int c, int x, int y, int** Board) {
  if (x < 0 || x >= 102 || y < 0 || y >= 102 || Board[x][y] == 0) {
    return false;
  } else if (Board[x][y] == c) {
    Board[x][y] = 0;
    if (x == xg && y == yg) {
      return true;
    }
    return DFS(c, x + 1, y, Board) ||
           DFS(c, x, y + 1, Board) ||
           DFS(c, x - 1, y, Board) ||
           DFS(c, x, y - 1, Board);
  }
  return false;
}

int main() {
  int w, h;
  while (true) {
    std::cin >> w >> h;
    if (w == 0 && h == 0)
      break;
      
    int** Board = new int*[w];
    for (int i = 0; i < w; i++) {
      Board[i] = new int[h];
    }
    
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        Board[i][j] = -1;
      }
    }
    
    int xs, ys, xg, yg;
    std::cin >> xs >> ys >> xg >> yg;
    
    int n, c, d, x, y;
    std::cin >> n;
    for (int t = 0; t < n; t++) {
      std::cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++) {
          Board[x + j][y + i] = c;
        }
      }
    }
    
    bool isOK = DFS(Board[xs][ys], xs, ys, Board);
    if (isOK)
      std::cout << "OK\n";
    else
      std::cout << "NG\n";
      
    for (int i = 0; i < w; i++) {
      delete[] Board[i];
    }
    delete[] Board;
  }
  
  return 0;
}
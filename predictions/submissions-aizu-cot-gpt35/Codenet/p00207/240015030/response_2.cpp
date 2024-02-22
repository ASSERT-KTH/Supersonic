#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool DFS(int c, int x, int y, int** Board, int w, int h) {
  if (Board[x][y] != c) {
    return false;
  } else if (x == xg && y == yg) {
    return true;
  }
  Board[x][y] = 0;
  if (x + 1 < w && DFS(c, x + 1, y, Board, w, h)) {
    return true;
  }
  if (y + 1 < h && DFS(c, x, y + 1, Board, w, h)) {
    return true;
  }
  if (x - 1 >= 0 && DFS(c, x - 1, y, Board, w, h)) {
    return true;
  }
  if (y - 1 >= 0 && DFS(c, x, y - 1, Board, w, h)) {
    return true;
  }
  return false;
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    int** Board = new int*[w];
    for (int i = 0; i < w; i++) {
      Board[i] = new int[h];
      for (int j = 0; j < h; j++) {
        Board[i][j] = -1;
      }
    }
    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++) {
          if (x + j < w && y + i < h) {
            Board[x + j][y + i] = c;
          }
        }
      }
    }
    bool isOK = DFS(Board[xs][ys], xs, ys, Board, w, h);
    if (isOK) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
    for (int i = 0; i < w; i++) {
      delete[] Board[i];
    }
    delete[] Board;
  }
}
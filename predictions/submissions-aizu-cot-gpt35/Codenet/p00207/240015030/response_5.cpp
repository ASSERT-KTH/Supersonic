#include <iostream>
using namespace std;

void DFS(int c, int x, int y, int* Board, int w, int h) {
  if (Board[y * w + x] != c) {
    return;
  } else if (x == xg && y == yg) {
    isOK = true;
    return;
  }
  Board[y * w + x] = 0;
  if (x + 1 < w) DFS(c, x + 1, y, Board, w, h);
  if (y + 1 < h) DFS(c, x, y + 1, Board, w, h);
  if (x - 1 >= 0) DFS(c, x - 1, y, Board, w, h);
  if (y - 1 >= 0) DFS(c, x, y - 1, Board, w, h);
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;

    int* Board = new int[w * h];
    int n, c, d, x, y;
    cin >> n;
    for (int i = 0; i < w * h; i++) {
      Board[i] = -1;
    }
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[(y + i) * w + (x + j)] = c;
      }
    }

    bool isOK = false;
    DFS(Board[xs][ys], xs, ys, Board, w, h);
    delete[] Board;

    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
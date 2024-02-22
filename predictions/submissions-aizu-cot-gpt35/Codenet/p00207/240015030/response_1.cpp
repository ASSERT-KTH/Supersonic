#include <iostream>
using namespace std;

bool isOK;
int xs, ys, xg, yg;
int Board[101][101];

void DFS(int c, int x, int y) {
  if (Board[x][y] != c) {
    return;
  } else if (x == xg && y == yg) {
    isOK = true;
    return;
  }
  Board[x][y] = 0;
  
  if (x < xg)
    DFS(c, x + 1, y);
  
  if (y < yg)
    DFS(c, x, y + 1);
  
  if (x > 0)
    DFS(c, x - 1, y);
  
  if (y > 0)
    DFS(c, x, y - 1);
}

int main() {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    isOK = false;
    xs = 0, ys = 0, xg = 0, yg = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
        Board[j][i] = -1;
    }
    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[x + j][y + i] = c;
      }
    }
    DFS(Board[xs][ys], xs, ys);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
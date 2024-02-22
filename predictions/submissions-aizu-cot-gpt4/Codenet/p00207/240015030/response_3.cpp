#include <iostream>
#include <algorithm>
using namespace std;

void DFS(int Board[102][102], int c, int x, int y, int xg, int yg, bool &isOK) {
  if (Board[x][y] != c || x == xg && y == yg) {
    isOK = (x == xg && y == yg);
    return;
  }
  Board[x][y] = 0;
  DFS(Board, c, x + 1, y, xg, yg, isOK);
  DFS(Board, c, x, y + 1, xg, yg, isOK);
  DFS(Board, c, x - 1, y, xg, yg, isOK);
  DFS(Board, c, x, y - 1, xg, yg, isOK);
}

int main() {
  int w, h;
  while (true) {
    scanf("%d%d", &w, &h);
    if (w == 0 && h == 0)
      break;
    bool isOK = false;
    int Board[102][102];
    fill(&Board[0][0], &Board[0][0] + sizeof(Board), -1);
    int xs, ys, xg, yg;
    scanf("%d%d%d%d", &xs, &ys, &xg, &yg);
    int n, c, d, x, y;
    scanf("%d", &n);
    for (int t = 0; t < n; t++) {
      scanf("%d%d%d%d", &c, &d, &x, &y);
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[x + j][y + i] = c;
      }
    }
    DFS(Board, Board[xs][ys], xs, ys, xg, yg, isOK);
    if (isOK)
      printf("OK\n");
    else
      printf("NG\n");
  }
  return 0;
}
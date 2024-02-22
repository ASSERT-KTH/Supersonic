#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<int>>& Board, int c, int x, int y, int xg, int yg) {
  if (Board[x][y] != c) {
    return false;
  } else if (x == xg && y == yg) {
    return true;
  }
  Board[x][y] = 0;
  return DFS(Board, c, x + 1, y, xg, yg) || DFS(Board, c, x, y + 1, xg, yg) || DFS(Board, c, x - 1, y, xg, yg) || DFS(Board, c, x, y - 1, xg, yg);
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    vector<vector<int>> Board(102, vector<int>(102, -1));
    int xs, ys, xg, yg;
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
    if (DFS(Board, Board[xs][ys], xs, ys, xg, yg))
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
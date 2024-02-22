#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Cell {
  int x, y;
  Cell(int x, int y) : x(x), y(y) {}
};

bool Board[102][102];
int xs, ys, xg, yg;

// We've inlined the DFS function and implemented it iteratively
inline void DFS(int c) {
  stack<Cell> stack;
  stack.push(Cell(xs, ys));
  while (!stack.empty()) {
    Cell cell = stack.top();
    stack.pop();
    int x = cell.x, y = cell.y;
    if (x < 0 || y < 0 || x >= 102 || y >= 102 || Board[x][y] != c) continue;
    if (x == xg && y == yg) {
      Board[x][y] = 0;
      cout << "OK" << endl;
      return;
    }
    Board[x][y] = 0;
    stack.push(Cell(x + 1, y));
    stack.push(Cell(x, y + 1));
    stack.push(Cell(x - 1, y));
    stack.push(Cell(x, y - 1));
  }
  cout << "NG" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    memset(Board, -1, sizeof(Board));
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
    DFS(Board[xs][ys]);
  }
  return 0;
}
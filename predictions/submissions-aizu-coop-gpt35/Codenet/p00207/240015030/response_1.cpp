#include <iostream>
#include <vector>
using namespace std;

bool DFS(const vector<vector<bool>>& board, int c, int x, int y, int xg, int yg) {
  if (board[x][y] || x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
    return false;
  } else if (x == xg && y == yg) {
    return true;
  }
  board[x][y] = true;
  if (DFS(board, c, x + 1, y, xg, yg) || DFS(board, c, x, y + 1, xg, yg) || DFS(board, c, x - 1, y, xg, yg) || DFS(board, c, x, y - 1, xg, yg)) {
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
    vector<vector<bool>> board(w, vector<bool>(h, false));
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
          board[x + j][y + i] = true;
      }
    }
    if (DFS(board, board[xs][ys], xs, ys, xg, yg))
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
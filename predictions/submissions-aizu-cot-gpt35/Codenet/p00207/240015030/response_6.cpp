#include <iostream>
#include <vector>
using namespace std;

bool isOK;
vector<vector<int>> board;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
  if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
    return;
  }
  
  if (board[x][y] != c) {
    return;
  } else if (x == xg && y == yg) {
    isOK = true;
    return;
  }
  
  board[x][y] = 0;
  DFS(c, x + 1, y);
  DFS(c, x, y + 1);
  DFS(c, x - 1, y);
  DFS(c, x, y - 1);
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    isOK = false;
    
    board.resize(w, vector<int>(h, -1));
    
    cin >> xs >> ys >> xg >> yg;
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
      int c, d, x, y;
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          board[x + j][y + i] = c;
      }
    }
    DFS(board[xs][ys], xs, ys);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
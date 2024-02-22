#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Board;
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
  if (Board[x][y] != c) {
    return;
  } else if (x == xg && y == yg) {
    isOK = true;
    return;
  }
  Board[x][y] = 0;

  // Only recursively call for adjacent cells within the bounds of the Board array
  if (x + 1 < Board.size()) {
    DFS(c, x + 1, y);
  }
  if (y + 1 < Board[x].size()) {
    DFS(c, x, y + 1);
  }
  if (x - 1 >= 0) {
    DFS(c, x - 1, y);
  }
  if (y - 1 >= 0) {
    DFS(c, x, y - 1);
  }
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    isOK = false;

    // Resize the Board array based on the input values of w and h
    Board.resize(w + 2, vector<int>(h + 2, -1));

    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);

      // Optimize the loops to iterate only over the necessary range of cells
      for (int i = y; i < y + hb; i++) {
        for (int j = x; j < x + wb; j++) {
          Board[j][i] = c;
        }
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
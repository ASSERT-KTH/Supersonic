#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<int>>& Board, int c, int x, int y, int xg, int yg) {
  const int h = Board.size();
  const int w = Board[0].size();

  if (Board[x][y] != c) {
    return false;
  } else if (x == xg && y == yg) {
    return true;
  }

  Board[x][y] = 0;
  if (x + 1 < w && DFS(Board, c, x + 1, y, xg, yg)) {
    return true;
  }
  if (y + 1 < h && DFS(Board, c, x, y + 1, xg, yg)) {
    return true;
  }
  if (x - 1 >= 0 && DFS(Board, c, x - 1, y, xg, yg)) {
    return true;
  }
  if (y - 1 >= 0 && DFS(Board, c, x, y - 1, xg, yg)) {
    return true;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;

    vector<vector<int>> Board(h, vector<int>(w, -1));

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
          Board[y + i][x + j] = c;
      }
    }

    if (DFS(Board, Board[xs][ys], xs, ys, xg, yg)) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  }

  return 0;
}
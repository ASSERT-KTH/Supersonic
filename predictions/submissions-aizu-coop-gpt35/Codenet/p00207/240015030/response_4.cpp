#include <iostream>
using namespace std;

bool isOK;
int xs, ys, xg, yg;
int** Board;

void DFS(int c, int x, int y) {
  if (x == xg && y == yg) {
    isOK = true;
    return;
  } else if (Board[x][y] != c) {
    return;
  }
  Board[x][y] = 0;

  // Check if adjacent cells are within bounds before making recursive calls
  if (x + 1 < xs && Board[x + 1][y] == c) {
    DFS(c, x + 1, y);
  }
  if (y + 1 < ys && Board[x][y + 1] == c) {
    DFS(c, x, y + 1);
  }
  if (x > 0 && Board[x - 1][y] == c) {
    DFS(c, x - 1, y);
  }
  if (y > 0 && Board[x][y - 1] == c) {
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

    // Resize the Board array to the actual dimensions of the maze
    Board = new int*[w];
    for (int i = 0; i < w; i++) {
      Board[i] = new int[h];
      for (int j = 0; j < h; j++) {
        Board[i][j] = -1;
      }
    }

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
    DFS(Board[xs][ys], xs, ys);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;

    // Deallocate memory for the Board array
    for (int i = 0; i < w; i++) {
      delete[] Board[i];
    }
    delete[] Board;
  }
  return 0;
}
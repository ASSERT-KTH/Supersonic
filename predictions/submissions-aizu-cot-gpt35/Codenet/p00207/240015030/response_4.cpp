#include <iostream>
using namespace std;

const int MAX_BOARD_SIZE = 102;
int Board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
  if (Board[x][y] != c) {
    return;
  }
  if (x == xg && y == yg) {
    isOK = true;
    return;
  }
  Board[x][y] = 0;

  // Prioritize the direction towards the goal
  if (abs(x - xg) < abs(y - yg)) {
    DFS(c, x + 1, y);
    DFS(c, x - 1, y);
    DFS(c, x, y + 1);
    DFS(c, x, y - 1);
  } else {
    DFS(c, x, y + 1);
    DFS(c, x, y - 1);
    DFS(c, x + 1, y);
    DFS(c, x - 1, y);
  }
}

int main() {
  int xs, ys, xg, yg;
  do {
    cin >> xs >> ys;
    if (xs == 0 && ys == 0) {
      break;
    }
    isOK = false;

    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
      for (int j = 0; j < MAX_BOARD_SIZE; j++) {
        Board[j][i] = 0;
      }
    }

    cin >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      for (int i = 0; i < 2 + (!d * 2); i++) {
        for (int j = 0; j < 2 + (d * 2); j++) {
          Board[x + j][y + i] = c;
        }
      }
    }

    DFS(Board[xs][ys], xs, ys);

    if (isOK) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  } while (true);

  return 0;
}
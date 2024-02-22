#include <iostream>

bool DFS(int c, int x, int y, int** Board) {
  if (Board[x][y] != c) {
    return false;
  } else if (Board[x][y] == 0) {
    return false;
  } else if (x == Board[0][0] && y == Board[0][1]) {
    return true;
  }
  Board[x][y] = 0;
  bool result = DFS(c, x + 1, y, Board) || DFS(c, x, y + 1, Board) ||
                DFS(c, x - 1, y, Board) || DFS(c, x, y - 1, Board);
  return result;
}

int main() {
  int w, h;
  while (true) {
    std::cin >> w >> h;
    if (w == 0 && h == 0)
      break;

    int** Board = new int* [w + 2];
    for (int i = 0; i < w + 2; i++) {
      Board[i] = new int[h + 2]{0};
    }

    std::cin >> Board[0][0] >> Board[0][1] >> Board[0][2] >> Board[0][3];
    int n, c, d, x, y;
    std::cin >> n;
    for (int t = 0; t < n; t++) {
      std::cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[x + j][y + i] = c;
      }
    }

    bool isOK = DFS(Board[Board[0][0]][Board[0][1]], Board[0][0], Board[0][1], Board);

    for (int i = 0; i < w + 2; i++) {
      delete[] Board[i];
    }
    delete[] Board;

    if (isOK)
      std::cout << "OK" << std::endl;
    else
      std::cout << "NG" << std::endl;
  }
  return 0;
}
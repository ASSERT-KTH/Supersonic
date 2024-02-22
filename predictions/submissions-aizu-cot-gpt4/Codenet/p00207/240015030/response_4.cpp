#include <iostream>
#include <array>
#include <stack>

using namespace std;

void DFS(array<array<bool, 102>, 102>& Board, bool& isOK, int xs, int ys, int xg, int yg) {
  stack<pair<int, int>> s;
  s.push({xs, ys});
  while (!s.empty()) {
    int x = s.top().first;
    int y = s.top().second;
    s.pop();
    if (Board[x][y]) {
      if (x == xg && y == yg) {
        isOK = true;
        return;
      }
      Board[x][y] = false;
      s.push({x + 1, y});
      s.push({x, y + 1});
      s.push({x - 1, y});
      s.push({x, y - 1});
    }
  }
}

int main() {
  array<array<bool, 102>, 102> Board;
  bool isOK;
  int xs, ys, xg, yg;
  int w, h;
  while (scanf("%d %d", &w, &h), w || h) {
    fill(Board.begin(), Board.end(), false);
    scanf("%d %d %d %d", &xs, &ys, &xg, &yg);
    int n, c, d, x, y;
    scanf("%d", &n);
    for (int t = 0; t < n; t++) {
      scanf("%d %d %d %d", &c, &d, &x, &y);
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[x + j][y + i] = c;
      }
    }
    DFS(Board, isOK, xs, ys, xg, yg);
    if (isOK)
      printf("OK\n");
    else
      printf("NG\n");
  }
  return 0;
}
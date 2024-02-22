#include <iostream>
#include <cstring>
using namespace std;

int Board[102][102];
int xs, ys, xg, yg;

bool DFS(int c, int x, int y) {
  if (x < 0 || x > 101 || y < 0 || y > 101 || Board[x][y] != c)
    return false;
  if (x == xg && y == yg)
    return true;
  
  Board[x][y] = -2;
  return DFS(c, x + 1, y) || DFS(c, x, y + 1) || DFS(c, x - 1, y) || DFS(c, x, y - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
      
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
    if (DFS(Board[xs][ys], xs, ys))
      cout << "OK" << '\n';
    else
      cout << "NG" << '\n';
  }
  return 0;
}
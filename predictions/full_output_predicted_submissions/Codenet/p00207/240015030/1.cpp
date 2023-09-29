#include <iostream>
using namespace std;
int Board[102][102];
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
  DFS(c, x + 1, y);
  DFS(c, x, y + 1);
  DFS(c, x - 1, y);
  DFS(c, x, y - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    isOK = false;
    for (int i = 0; i < 102; i++) {
      for (int j = 0; j < 102; j++)
        Board[j][i] = -1;
    }
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
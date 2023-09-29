#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> Board(102, vector<int>(102));
bool isOK;
int xs, ys, xg, yg;
void DFS(int c, int x, int y) {
  if (x < 0 || x >= 102 || y < 0 || y >= 102 || Board[x][y] != c) {
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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h;
  while (cin >> w >> h && (w || h)) {
    isOK = false;
    for (auto &row : Board) {
      fill(row.begin(), row.end(), -1);
    }
    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    while (n--) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[x + j][y + i] = c;
      }
    }
    DFS(Board[xs][ys], xs, ys);
    cout << (isOK ? "OK" : "NG") << '\n';
  }
  return 0;
}
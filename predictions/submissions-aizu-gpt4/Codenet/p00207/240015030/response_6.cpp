#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 102;

int Board[MAX_SIZE][MAX_SIZE];
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
  if(x < 0 || y < 0 || x >= MAX_SIZE || y >= MAX_SIZE || Board[x][y] != c) {
    return;
  }
  
  if (x == xg && y == yg) {
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
  while (cin >> w >> h && (w != 0 || h != 0)) {
    isOK = false;
    memset(Board, -1, sizeof(Board));

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
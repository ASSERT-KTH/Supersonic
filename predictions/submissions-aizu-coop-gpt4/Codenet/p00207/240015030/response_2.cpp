#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int Board[102][102];
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
  stack<pair<int, int>> stk;
  stk.push({x, y});

  while (!stk.empty()) {
    int x = stk.top().first;
    int y = stk.top().second;
    stk.pop();

    if (Board[x][y] != c)
      continue;
    if (x == xg && y == yg) {
      isOK = true;
      return;
    }
    Board[x][y] = 0;
    stk.push({x + 1, y});
    stk.push({x, y + 1});
    stk.push({x - 1, y});
    stk.push({x, y - 1});
  }
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    isOK = false;
    memset(Board, -1, sizeof(Board));
    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        memset(&Board[x][y + i], c, wb * sizeof(int));
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
#include <iostream>
#include <stack>
using namespace std;

struct Position {int x, y;};
bool visited[102][102];

void DFS(int c, int x, int y, int xg, int yg, int w, int h, int Board[102][102], bool& isOK) {
  stack<Position> s;
  s.push({x, y});
  while (!s.empty()) {
    Position p = s.top();
    s.pop();
    if (p.x < 0 || p.x >= w || p.y < 0 || p.y >= h || visited[p.x][p.y] || Board[p.x][p.y] != c)
      continue;
    visited[p.x][p.y] = true;
    if (p.x == xg && p.y == yg) {
      isOK = true;
      return;
    }
    s.push({p.x + 1, p.y});
    s.push({p.x, p.y + 1});
    s.push({p.x - 1, p.y});
    s.push({p.x, p.y - 1});
  }
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    bool isOK = false;
    int Board[102][102];
    int xs, ys, xg, yg;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
        Board[j][i] = -1, visited[j][i] = false;
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
    DFS(Board[xs][ys], xs, ys, xg, yg, w, h, Board, isOK);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isOK;
int xs, ys, xg, yg;

struct Point {
  int x, y;
};

void DFS(vector<vector<int>>& Board, int c) {
  stack<Point> s;
  s.push({xs, ys});
  int h = Board.size(), w = Board[0].size();

  while (!s.empty()) {
    Point p = s.top();
    s.pop();

    if (p.x < 0 || p.y < 0 || p.x >= w || p.y >= h || Board[p.y][p.x] != c)
      continue;

    if (p.x == xg && p.y == yg) {
      isOK = true;
      break;
    }

    Board[p.y][p.x] = 0;

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
    isOK = false;
    vector<vector<int>> Board(h, vector<int>(w, -1));
    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[y + i][x + j] = c;
      }
    }
    DFS(Board, Board[ys][xs]);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
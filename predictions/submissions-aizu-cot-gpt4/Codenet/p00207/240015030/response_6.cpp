#include <iostream>
#include <stack>
using namespace std;

bool isOK;
int xs, ys, xg, yg;

void DFS(int Board[102][102], int c, int x, int y) {
  stack<pair<int, int>> s;
  s.push({x, y});

  while(!s.empty()){
    x = s.top().first;
    y = s.top().second;
    s.pop();

    if (Board[x][y] != c) {
      continue;
    } else if (x == xg && y == yg) {
      isOK = true;
      return;
    }

    Board[x][y] = 0;
    s.push({x+1, y});
    s.push({x, y+1});
    s.push({x-1, y});
    s.push({x, y-1});
  }
}

int main() {
  int w, h, n, c, d, x, y;
  int Board[102][102];

  while (cin >> w >> h && w && h) {
    isOK = false;
    memset(Board, -1, sizeof(Board));

    cin >> xs >> ys >> xg >> yg;
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

    DFS(Board, Board[xs][ys], xs, ys);

    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
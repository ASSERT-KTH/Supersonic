#include <iostream>
#include <stack>
using namespace std;

int Board[102][102];
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
  stack<pair<int, int>> s;
  s.push(make_pair(x, y));

  while (!s.empty()) {
    pair<int, int> p = s.top();
    s.pop();
    x = p.first;
    y = p.second;

    if (x < 0 || y < 0 || x >= 102 || y >= 102 || Board[x][y] != c) {
      continue;
    }

    if (x == xg && y == yg) {
      isOK = true;
      return;
    }

    Board[x][y] = 0;

    s.push(make_pair(x + 1, y));
    s.push(make_pair(x, y + 1));
    s.push(make_pair(x - 1, y));
    s.push(make_pair(x, y - 1));
  }
}

int main() {
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
    DFS(Board[xs][ys], xs, ys);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
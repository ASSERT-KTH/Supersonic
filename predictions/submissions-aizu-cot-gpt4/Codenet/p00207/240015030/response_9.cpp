#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<pair<int, int>, int> Board;
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
  stack<pair<int, int>> s;
  s.push({x, y});
  
  while (!s.empty()) {
    pair<int, int> p = s.top();
    s.pop();
    
    int x = p.first;
    int y = p.second;

    if (Board[{x, y}] != c) {
      continue;
    } else if (x == xg && y == yg) {
      isOK = true;
      return;
    }
    Board[{x, y}] = 0;
    s.push({x+1, y});
    s.push({x, y+1});
    s.push({x-1, y});
    s.push({x, y-1});
  }
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    isOK = false;
    Board.clear();
    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[{x + j, y + i}] = c;
      }
    }
    DFS(Board[{xs, ys}], xs, ys);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
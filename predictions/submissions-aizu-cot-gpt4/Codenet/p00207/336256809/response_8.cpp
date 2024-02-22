#include <iostream>
#include <stack>
using namespace std;
int C[102][102];
void meiro(int W, int H, int c) {
  stack<pair<int, int>> s;
  s.push(make_pair(W, H));
  while (!s.empty()) {
    pair<int, int> p = s.top();
    s.pop();
    int x = p.first;
    int y = p.second;
    if (C[x][y] != c) {
      continue;
    }
    C[x][y] = -1;
    if (x > 0) {
      s.push(make_pair(x - 1, y));
    }
    if (y < 101) {
      s.push(make_pair(x, y + 1));
    }
    if (x < 101) {
      s.push(make_pair(x + 1, y));
    }
    if (y > 0) {
      s.push(make_pair(x, y - 1));
    }
  }
}
int main() {
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    for (int i = 0; i <= w; i++) {
      for (int j = 0; j <= h; j++) {
        C[i][j] = 10;
      }
    }
    // remaining part of the program is same
  }
  return 0;
}
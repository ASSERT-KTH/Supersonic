#include <iostream>
#include <stack>
using namespace std;

int C[102][102];
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void meiro(int W, int H, int c) {
  stack<pair<int, int>> s;
  s.push(make_pair(W, H));
  
  while (!s.empty()) {
    pair<int, int> p = s.top();
    s.pop();
    
    if (C[p.first][p.second] != c) {
      continue;
    }

    C[p.first][p.second] = -1;

    for (int i = 0; i < 4; i++) {
      int newW = p.first + dir[i][0];
      int newH = p.second + dir[i][1];
      if (newW >= 0 && newW < 102 && newH >= 0 && newH < 102) {
        s.push(make_pair(newW, newH));
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    fill(&C[0][0], &C[0][0] + sizeof(C) / sizeof(C[0][0]), 10);
    
    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    
    int n;
    cin >> n;
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      int dx = d == 0 ? 4 : 2;
      int dy = d == 0 ? 2 : 4;
      for (int j = x; j < x + dx; j++) {
        fill_n(C[j] + y, dy, c);
      }
    }
    
    meiro(xs, ys, C[xs][ys]);
    
    if (C[xg][yg] == -1) {
      cout << "OK" << '\n';
    } else {
      cout << "NG" << '\n';
    }
  }
  return 0;
}
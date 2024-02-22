#include <iostream>
#include <stack>
using namespace std;

int C[102][102];

void meiro(int W, int H, int c) {
  stack<pair<int, int>> stk;
  stk.push({W, H});

  while (!stk.empty()) {
    pair<int, int> p = stk.top();
    stk.pop();

    int W = p.first, H = p.second;
    if (C[W][H] != c) {
      continue;
    }

    C[W][H] = -1;
    stk.push({W - 1, H});
    stk.push({W, H + 1});
    stk.push({W + 1, H});
    stk.push({W, H - 1});
  }
}

int main() {
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    int xmin = 101, ymin = 101, xmax = 0, ymax = 0;

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    xmin = min(xmin, min(xs, xg));
    ymin = min(ymin, min(ys, yg));
    xmax = max(xmax, max(xs, xg));
    ymax = max(ymax, max(ys, yg));

    int n;
    cin >> n;
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      xmin = min(xmin, x);
      ymin = min(ymin, y);
      if (d == 0) {
        xmax = max(xmax, x + 4);
        ymax = max(ymax, y + 2);
        for (int j = x; j < x + 4; j++) {
          for (int k = y; k < y + 2; k++) {
            C[j][k] = c;
          }
        }
      } else {
        xmax = max(xmax, x + 2);
        ymax = max(ymax, y + 4);
        for (int j = x; j < x + 2; j++) {
          for (int k = y; k < y + 4; k++) {
            C[j][k] = c;
          }
        }
      }
    }

    for (int i = xmin; i <= xmax; i++) {
      for (int j = ymin; j <= ymax; j++) {
        if (i < xmin || i > xmax || j < ymin || j > ymax) {
          C[i][j] = 10;
        }
      }
    }

    meiro(xs, ys, C[xs][ys]);
    if (C[xg][yg] == -1) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  }
  return 0;
}
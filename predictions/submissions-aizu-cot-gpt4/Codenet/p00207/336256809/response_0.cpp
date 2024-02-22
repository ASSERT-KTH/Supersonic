#include <iostream>
#include <algorithm>
using namespace std;

int C[102][102];

void meiro(int W, int H, int c) {
  if (C[W][H] != c) {
    return;
  }
  C[W][H] = -1;
  meiro(W - 1, H, c);
  meiro(W, H + 1, c);
  meiro(W + 1, H, c);
  meiro(W, H - 1, c);
}

int main() {

  // Initialize the array once at the start
  for (int i = 0; i < 102; i++) {
    std::fill(C[i], C[i] + 102, 10);
  }

  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int n;
    cin >> n;
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      if (d == 0) {
        for (int j = x; j < x + 4; j++) {
          std::fill(C[j] + y, C[j] + y + 2, c);
        }
      } else {
        for (int j = x; j < x + 2; j++) {
          std::fill(C[j] + y, C[j] + y + 4, c);
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
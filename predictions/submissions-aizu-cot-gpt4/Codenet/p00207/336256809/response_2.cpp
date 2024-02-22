#include <iostream>
using namespace std;
int C[101][101];

void meiro(int W, int H, int c) {
  C[W][H] = -1;
  if (W > 0 && C[W - 1][H] == c) meiro(W - 1, H, c);
  if (H < 100 && C[W][H + 1] == c) meiro(W, H + 1, c);
  if (W < 100 && C[W + 1][H] == c) meiro(W + 1, H, c);
  if (H > 0 && C[W][H - 1] == c) meiro(W, H - 1, c);
}

int main() {
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    for (int i = 0; i <= w; i++)
      for (int j = 0; j <= h; j++)
        C[i][j] = 10;

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int n;
    cin >> n;
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      if (d == 0) {
        for (int j = x; j < x + 4; j++)
          for (int k = y; k < y + 2; k++)
            C[j][k] = c;
      } else {
        for (int j = x; j < x + 2; j++)
          for (int k = y; k < y + 4; k++)
            C[j][k] = c;
      }
    }
    if (C[xs][ys] != -1) meiro(xs, ys, C[xs][ys]);
    if (C[xg][yg] == -1)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
#include <cstdio>
#define MAX 102
int C[MAX][MAX];

void meiro(int W, int H, int c) {
  if (W < 0 || W >= MAX || H < 0 || H >= MAX || C[W][H] != c)
    return;

  C[W][H] = -1;
  meiro(W - 1, H, c);
  meiro(W, H + 1, c);
  meiro(W + 1, H, c);
  meiro(W, H - 1, c);
}

int main() {
  while (1) {
    int w, h;
    scanf("%d %d", &w, &h);
    if (w == 0 && h == 0)
      break;

    int xs, ys, xg, yg;
    scanf("%d %d %d %d", &xs, &ys, &xg, &yg);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
      int c, d, x, y;
      scanf("%d %d %d %d", &c, &d, &x, &y);

      for (int j = x; j < (d == 0 ? x + 4 : x + 2); j++) {
        for (int k = y; k < (d == 0 ? y + 2 : y + 4); k++) {
          C[j][k] = c;
        }
      }
    }

    meiro(xs, ys, C[xs][ys]);
    if (C[xg][yg] == -1)
      printf("OK\n");
    else
      printf("NG\n");
  }
  return 0;
}
#include <stdio.h>
#include <string.h>

#define ROW 100
#define COL 100

int main() {
  int inact[ROW][COL];
  int act[COL];
  int ans[ROW];
  int row, col;
  int i, j;

  memset(inact, 0, sizeof(inact));
  memset(act, 0, sizeof(act));
  memset(ans, 0, sizeof(ans));

  scanf("%d %d", &row, &col);

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }

  for (i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }

  for (j = 0; j < col; j++) {
    for (i = 0; i < row; i++) {
      ans[i] += inact[i][j] * act[j];
    }
  }

  for (i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
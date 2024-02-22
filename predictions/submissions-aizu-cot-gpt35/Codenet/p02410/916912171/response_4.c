#include <stdio.h>
#include <string.h>

int main() {
  int row, col;
  scanf("%d %d", &row, &col);

  int inact[row][col];
  int act[col];
  int ans[row];

  memset(inact, 0, sizeof(inact));
  memset(act, 0, sizeof(act));
  memset(ans, 0, sizeof(ans));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }

  for (int i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }

  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      ans[j] += inact[j][i] * act[i];
    }
  }

  for (int i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
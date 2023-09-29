#include <stdio.h>
int main() {
  int inact[100][100];
  int act[100];
  int ans[100];
  int row, col;
  int i, j;
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 50; j++) {
      inact[i][j] = 0;
    }
    act[i] = 0;
    ans[i] = 0;
  }
  scanf("%d %d", &row, &col);
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }
  for (i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      ans[i] += inact[i][j] * act[j];
    }
  }
  for (i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}

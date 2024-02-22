#include <stdio.h>
int main() {
  unsigned int inact[100][100];
  unsigned int act[100];
  unsigned int ans[100];
  unsigned int row, col;
  unsigned int i, j;
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
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

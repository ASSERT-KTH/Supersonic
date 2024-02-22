#include <stdio.h>
int main() {
  int inact[100];
  int act[100];
  int ans[100];
  int row, col;
  int i, j;

  scanf("%d %d", &row, &col);

  for (i = 0; i < col; i++) {
    act[i] = 0;
  }

  for (i = 0; i < row; i++) {
    ans[i] = 0;
  }

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[j]);
      ans[i] += inact[j] * act[j];
    }
  }

  for (i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
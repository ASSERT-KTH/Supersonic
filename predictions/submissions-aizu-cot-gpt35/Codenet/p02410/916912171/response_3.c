#include <stdio.h>
#include <string.h>

int main() {
  int inact[100][100];
  int result[100];
  int row, col;
  int i, j;

  memset(inact, 0, sizeof(inact));
  scanf("%d %d", &row, &col);

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }

  for (i = 0; i < col; i++) {
    scanf("%d", &result[i]);
  }

  for (i = 0; i < row; i++) {
    register int sum = 0;
    for (j = 0; j < col; j++) {
      sum += inact[i][j] * result[j];
    }
    printf("%d\n", sum);
  }

  return 0;
}
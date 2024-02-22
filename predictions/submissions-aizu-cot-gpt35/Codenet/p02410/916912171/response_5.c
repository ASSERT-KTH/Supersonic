#include <stdio.h>
#include <stdlib.h>

int main() {
  int row, col;
  int i, j;

  scanf("%d %d", &row, &col);

  int** inact = (int**)malloc(row * sizeof(int*));
  for (i = 0; i < row; i++) {
    inact[i] = (int*)malloc(col * sizeof(int));
  }

  int* act = (int*)malloc(col * sizeof(int));
  int* ans = (int*)calloc(row, sizeof(int));

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

  for (i = 0; i < row; i++) {
    free(inact[i]);
  }
  free(inact);
  free(act);
  free(ans);

  return 0;
}
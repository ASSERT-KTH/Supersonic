#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int row, col;
  scanf("%d %d", &row, &col);

  int** inact = (int**)malloc(row * sizeof(int*));
  for (int i = 0; i < row; i++) {
    inact[i] = (int*)malloc(col * sizeof(int));
  }

  int* act = (int*)malloc(col * sizeof(int));
  int* ans = (int*)malloc(row * sizeof(int));

  memset(ans, 0, row * sizeof(int));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }

  for (int i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j += 4) {
      ans[i] += inact[i][j] * act[j];
      ans[i] += inact[i][j + 1] * act[j + 1];
      ans[i] += inact[i][j + 2] * act[j + 2];
      ans[i] += inact[i][j + 3] * act[j + 3];
    }
  }

  for (int i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }

  // Free dynamically allocated memory
  for (int i = 0; i < row; i++) {
    free(inact[i]);
  }
  free(inact);
  free(act);
  free(ans);

  return 0;
}
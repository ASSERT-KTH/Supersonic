#include <stdio.h>
#include <stdlib.h>

int main() {
  int row, col;
  int i, j;

  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &row, &col);

  if (row <= 0 || col <= 0) {
    printf("Invalid dimensions\n");
    return 1;
  }

  int **inact = (int **)malloc(row * sizeof(int *));
  for (i = 0; i < row; i++) {
    inact[i] = (int *)calloc(col, sizeof(int));
  }

  int *act = (int *)malloc(col * sizeof(int));
  int *ans = (int *)calloc(row, sizeof(int));

  printf("Enter the elements of the inactive matrix:\n");
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }

  printf("Enter the elements of the active vector:\n");
  for (i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j += 4) {
      ans[i] += inact[i][j] * act[j];
      ans[i] += inact[i][j + 1] * act[j + 1];
      ans[i] += inact[i][j + 2] * act[j + 2];
      ans[i] += inact[i][j + 3] * act[j + 3];
    }
  }

  printf("Result:\n");
  for (i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }

  // Free dynamically allocated memory
  for (i = 0; i < row; i++) {
    free(inact[i]);
  }
  free(inact);
  free(act);
  free(ans);

  return 0;
}
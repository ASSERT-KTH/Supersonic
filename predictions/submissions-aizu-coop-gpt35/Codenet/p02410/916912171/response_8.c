#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int row, col;
  int i, j;
  scanf("%d %d", &row, &col);

  // Dynamically allocate memory for the arrays
  int** inact = (int**)malloc(row * sizeof(int*));
  int* act = (int*)malloc(col * sizeof(int));
  int* ans = (int*)malloc(row * sizeof(int));

  // Initialize the arrays using memset
  for (i = 0; i < row; i++) {
    inact[i] = (int*)malloc(col * sizeof(int));
    memset(inact[i], 0, col * sizeof(int));
    ans[i] = 0;
  }
  memset(act, 0, col * sizeof(int));

  // Read input values
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
  }
  for (i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }

  // Perform matrix-vector multiplication with loop unrolling
  for (i = 0; i < row; i++) {
    int sum = 0;
    for (j = 0; j < col; j += 4) {
      sum += inact[i][j] * act[j];
      sum += inact[i][j + 1] * act[j + 1];
      sum += inact[i][j + 2] * act[j + 2];
      sum += inact[i][j + 3] * act[j + 3];
    }
    ans[i] = sum;
  }

  // Print the result
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
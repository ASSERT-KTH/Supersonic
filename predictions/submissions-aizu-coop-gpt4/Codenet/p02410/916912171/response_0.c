#include <stdio.h>
#include <stdlib.h> // Required for dynamic memory allocation

int main() {
  int **inact; // Declare as double pointer
  int act[100];
  int ans[100];
  int row, col;
  int i, j;

  scanf("%d %d", &row, &col);

  // Dynamic memory allocation for 'inact'
  inact = (int **)malloc(row * sizeof(int *));
  for (i = 0; i < row; i++) {
    inact[i] = (int *)malloc(col * sizeof(int));
  }

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &inact[i][j]);
    }
    ans[i] = 0; // Initialize 'ans'
  }

  for (i = 0; i < col; i++) {
    scanf("%d", &act[i]);
    act[i] = 0; // Initialize 'act'
  }

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      ans[i] += inact[i][j] * act[j];
    }
  }

  for (i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }

  // Free dynamically allocated memory
  for (i = 0; i < row; i++) {
    free(inact[i]);
  }
  free(inact);

  return 0;
}
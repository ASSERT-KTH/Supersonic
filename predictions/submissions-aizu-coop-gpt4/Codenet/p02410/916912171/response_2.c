#include <stdio.h>
#include <stdlib.h>

int main() {
  int row, col;
  scanf("%d %d", &row, &col);

  // Dynamically allocate memory
  int **inact = (int**) malloc(row * sizeof(int*));
  for(int i = 0; i < row; i++)
    inact[i] = (int*) malloc(col * sizeof(int));
  int *act = (int*) malloc(col * sizeof(int));
  int *ans = (int*) malloc(row * sizeof(int));

  // Use pointer arithmetic for initialization
  for (int *p = ans; p != ans + row; ++p)
    *p = 0;

  // Read input
  for (int i = 0; i < row; i++)
    for (int *p = inact[i]; p != inact[i] + col; ++p)
      scanf("%d", p);
  for (int *p = act; p != act + col; ++p)
    scanf("%d", p);

  // Compute multiplication
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      ans[i] += inact[i][j] * act[j];

  // Print results
  for (int *p = ans; p != ans + row; ++p)
    printf("%d\n", *p);

  // Free memory
  for(int i = 0; i < row; i++)
    free(inact[i]);
  free(inact);
  free(act);
  free(ans);

  return 0;
}
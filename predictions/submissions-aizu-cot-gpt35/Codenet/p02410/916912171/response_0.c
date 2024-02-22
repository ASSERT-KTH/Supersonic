#include <stdio.h>
#include <stdlib.h>

int main() {
  int row, col;
  int i, j;

  scanf("%d %d", &row, &col);

  int* inact = (int*) malloc(row * col * sizeof(int));
  int* act = (int*) malloc(col * sizeof(int));
  int* ans = (int*) calloc(row, sizeof(int));

  for (i = 0; i < row * col; i++) {
    scanf("%d", &inact[i]);
  }

  for (i = 0; i < col; i++) {
    scanf("%d", &act[i]);
  }

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      ans[i] += inact[i * col + j] * act[j];
    }
  }

  char ansString[1000];
  char* ansPtr = ansString;

  for (i = 0; i < row; i++) {
    ansPtr += sprintf(ansPtr, "%d\n", ans[i]);
  }

  printf("%s", ansString);

  free(inact);
  free(act);
  free(ans);

  return 0;
}
#include <stdio.h>
#include <string.h>
int main() {
  int inact[100][100];
  int act[100];
  int ans[100];
  int row, col;
  int i, j;

  // Initialize arrays using memset
  memset(inact, 0, sizeof(inact));
  memset(act, 0, sizeof(act));
  memset(ans, 0, sizeof(ans));

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
    // Unroll the 'col' loop by a factor of 4
    for (j = 0; j < col; j+=4) {
      ans[i] += inact[i][j] * act[j];
      ans[i] += inact[i][j+1] * act[j+1];
      ans[i] += inact[i][j+2] * act[j+2];
      ans[i] += inact[i][j+3] * act[j+3];
    }
    // If 'col' is not a multiple of 4, perform the operation for the remaining columns
    for (; j < col; j++) {
      ans[i] += inact[i][j] * act[j];
    }
  }
  for (i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
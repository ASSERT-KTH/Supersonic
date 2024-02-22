#include <stdio.h>

int main() {
  int inact[100][100];
  int act[100];
  int ans[100];
  int row, col;
  int i, j;

  // Step 1: Remove unnecessary initialization
  // The arrays inact, act, and ans are immediately overwritten in the subsequent loops,
  // so there is no need to initialize them with zeros.

  scanf("%d %d", &row, &col);

  // Step 3: Add error checking for row and col inputs
  if (row <= 0 || col <= 0) {
    printf("Invalid input: row and col must be positive integers.\n");
    return 1;
  }

  // Step 2: Optimize dot product calculation
  // Instead of using nested loops, we can use loop unrolling to reduce the number of loop iterations.

  // Unroll the outer loop by 4 iterations
  for (i = 0; i < row; i += 4) {
    // Unroll the inner loop by 4 iterations
    for (j = 0; j < col; j += 4) {
      // Accumulate the dot product using temporary variables
      int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

      for (int k = 0; k < 4; k++) {
        sum1 += inact[i][j + k] * act[j + k];
        sum2 += inact[i + 1][j + k] * act[j + k];
        sum3 += inact[i + 2][j + k] * act[j + k];
        sum4 += inact[i + 3][j + k] * act[j + k];
      }

      ans[i] += sum1;
      ans[i + 1] += sum2;
      ans[i + 2] += sum3;
      ans[i + 3] += sum4;
    }
  }

  // Handle the remaining rows and columns
  for (; i < row; i++) {
    for (j = 0; j < col; j++) {
      ans[i] += inact[i][j] * act[j];
    }
  }

  for (i = 0; i < row; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
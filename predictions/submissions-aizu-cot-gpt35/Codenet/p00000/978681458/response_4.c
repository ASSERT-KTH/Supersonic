#include <stdio.h>

int main(void) {
  int i, j;
  int results[10][10]; // 2D array to store the results

  // Calculate and store the results
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      results[i][j] = i * j;
    }
  }

  // Print the results
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      printf("%dx%d=%d\n", i, j, results[i][j]);
    }
  }

  return 0;
}
#include <stdio.h>

int main() {
  int results[9][9];  // Efficiently store the results in memory

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      results[i - 1][j - 1] = i * j;  // Store the results in the array
    }
  }

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      printf("%dx%d=%d\n", i, j, results[i - 1][j - 1]);  // Print the results from memory
    }
  }

  return 0;
}
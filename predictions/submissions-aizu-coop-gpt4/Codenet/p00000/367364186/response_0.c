#include <stdio.h>

int main() {
  int results[10][10] = { 0 }; // Initialize a 10x10 array to store multiplication results

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (results[i][j] == 0) // If the result hasn't been calculated yet
      {
        results[i][j] = i * j; // Calculate and store the result
        results[j][i] = results[i][j]; // Also store the result for the reversed pair (j, i)
      }

      printf("%d x %d = %d\n", i, j, results[i][j]); // Print the result from the array
    }
  }
  
  return 0;
}
#include <stdio.h>

int main(void) {
  int i, j;
  int results[10][10];
  
  // Precompute multiplication results
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      results[i][j] = i * j;
    }
  }
  
  char buffer[4];
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      // Convert i, j, and the result to strings
      sprintf(buffer, "%d", i);
      putchar(buffer[0]);
      putchar('x');
      sprintf(buffer, "%d", j);
      putchar(buffer[0]);
      putchar('=');
      sprintf(buffer, "%d", results[i][j]);
      
      // Print the result
      for (int k = 0; buffer[k] != '\0'; k++) {
        putchar(buffer[k]);
      }
      putchar('\n');
    }
  }
  
  return 0;
}
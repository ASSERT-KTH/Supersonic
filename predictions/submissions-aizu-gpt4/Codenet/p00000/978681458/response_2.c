#include <stdio.h>

int main(void) {
  int i, j;
  int results[10][10];
  
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      results[i][j] = i * j;
    }
  }
  
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      printf("%d x %d = %d\n", i, j, results[i][j]);
    }
  }

  return (0);
}
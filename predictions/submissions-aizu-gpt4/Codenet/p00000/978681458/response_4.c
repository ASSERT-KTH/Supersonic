#include <stdio.h>

int main(void) {
  int i, j, res[10][10];
  
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      res[i][j] = i * j;
    }
  }
  
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      printf("%dx%d=%d\n", i, j, res[i][j]);
    }
  }
  
  return 0;
}
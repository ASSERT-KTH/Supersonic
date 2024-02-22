#include <stdio.h>

int main(void) {
  int i, j;
  
  for (i = 1; i < 10; i++) {
    for (j = i; j < 10; j++) {
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }
  
  return 0;
}
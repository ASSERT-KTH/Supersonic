#include <stdio.h>

int main(void) {
  int i, j;
  int result;

  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= 9; j++) {
      result = i * j;
      printf("%dx%d=%d\n", i, j, result);
    }
  }

  return 0;
}
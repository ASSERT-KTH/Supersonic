#include <stdio.h>

int main(void) {
  int i, j, mult;
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      mult = i * j;
      printf("%dx%d=%d\n", i, j, mult);
    }
  }
  return 0;
}
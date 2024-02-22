#include <stdio.h>

int main(void) {
  int i, j;
  for (i = 0; i < 10; i++) {
    printf("%dx0=%d\n", i, i * 0);
    for (j = 1; j < 10; j++) {
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }
  return 0;
}
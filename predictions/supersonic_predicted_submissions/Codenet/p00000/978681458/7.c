#include <stdio.h>
int main(void) {
  int i, j;
  for (i = 1; i <= 100; i++) {
    for (j = 1; j <= 100; j++) {
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }
  return (0);
}

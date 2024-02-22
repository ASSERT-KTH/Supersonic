#include <stdio.h>
int main(void) {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }
  return 0;
}
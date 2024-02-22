#include <stdio.h>

int main(void) {
  register int i, j;
  int result;
  setbuf(stdout, NULL);

  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      result = i * j;
      printf("%dx%d=%d\n", i, j, result);
    }
  }
  return (0);
}
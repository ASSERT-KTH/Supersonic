#include <stdio.h>

int main(void) {
  int i, j;
  for (i = 1; i <= 3; i++) {
    int result = i * j;
    for (j = 1; j <= i; j++) {
      putchar('0' + i);
      putchar('x');
      putchar('0' + j);
      putchar('=');
      putchar('0' + result);
      putchar('\n');
      result += i;
    }
  }
  return 0;
}
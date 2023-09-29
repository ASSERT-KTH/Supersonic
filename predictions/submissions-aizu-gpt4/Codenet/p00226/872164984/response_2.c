#include <unistd.h>
#include <stdio.h>
#include <string.h>

char R[99];
int i, h, b;

int main(void) {
  char c;
  while (read(STDIN_FILENO, &c, 1) > 0)
  {
    if (++i > 9) {
      printf("%d %d\n", h, b - h);
      memset(R, 0, sizeof R);
      i = h = b = 0;
    }
    b += !!R[(unsigned)c];
    h += !(R[(unsigned)c] ^= 1 << i % 5);
  }
  return 0;
}
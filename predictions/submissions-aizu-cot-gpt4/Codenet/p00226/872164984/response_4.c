#include <stdio.h>
#include <string.h>

char R[256];
int i, h, b;

int main(void) {
  int c;
  while ((c = getchar()) != EOF) {
    if (i > 9) {
      printf("%d %d\n", h, b - h);
      memset(R, 0, sizeof(R));
      i = h = b = 0;
    }
    b += !!R[c];
    h += !(R[c] ^= 1 << i % 5);
    ++i;
  }
  return 0;
}
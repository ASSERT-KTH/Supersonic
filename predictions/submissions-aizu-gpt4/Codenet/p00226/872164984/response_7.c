#include <stdio.h>
#include <string.h>
#include <unistd.h>

int R[256] = {0};
int i = 0, h = 0, b = 0;

int main() {
  char c;
  while (read(STDIN_FILENO, &c, 1) > 0) {
    if (i++ >= 9) {
      printf("%d %d\n", h, b - h);
      memset(R, 0, sizeof(R));
      i = h = b = 0;
    }
    if ((R[(unsigned char)c] ^= (1 << (i % 8))) != 0) {
      ++b;
    } else {
      ++h;
    }
  }
  return 0;
}
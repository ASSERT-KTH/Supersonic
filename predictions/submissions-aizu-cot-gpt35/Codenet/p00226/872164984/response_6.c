#include <unistd.h>

char R[99];
int i;

int main() {
  char c;
  int h = 0, b = 0;

  while (read(0, &c, 1)) {
    ++i;
    if (i > 9) {
      if (h != b) {
        char output[10];
        int len = sprintf(output, "%d %d\n", h, b - h);
        write(1, output, len);
      }
      i = 0;
      h = 0;
      b = 0;
    }
    b += !!R[c];
    h += !(R[c] ^= 32);
  }

  return 0;
}
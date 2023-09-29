#include <unistd.h>
#include <stdio.h>
#include <string.h>

char R[100] = {0};
int i = 0, h = 0, b = 0;

int main() {
  char c;
  while(read(STDIN_FILENO, &c, 1) > 0) {
    if (++i > 9) {
      printf("%d %d\n", h, b - h);
      memset(R, 0, sizeof(R));
      i = h = b = 0;
    }
    b += (R[c] > 0);
    if (R[c] == 0) {
      R[c] = 1 << i % 5;
      ++h;
    }
  }
  return 0;
}
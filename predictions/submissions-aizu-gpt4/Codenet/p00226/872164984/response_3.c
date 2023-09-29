#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define SIZE 99
#define LIMIT 9

char R[SIZE];
int i, h, b;

int main() {
  char c;
  while (read(STDIN_FILENO, &c, 1) > 0) {
    if (i > LIMIT) {
      memset(R, 0, sizeof(R));
      printf("%d %d\n", h, b - h);
      i = h = b = 0;
    }
    b += !!(R[c]);
    h += !(R[c] ^= 1 << i % 5);
    ++i;
  }
  return 0;
}
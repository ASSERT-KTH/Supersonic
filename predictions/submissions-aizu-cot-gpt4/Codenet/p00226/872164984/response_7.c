#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 4096

char R[99];
int i, h, b;
char buf[BUF_SIZE];
int c;

int main() {
  int n, j;
  while ((n = read(0, buf, BUF_SIZE)) > 0) {
    for (j = 0; j < n; ++j) {
      c = buf[j];
      b += !!R[c], h += !(R[c] ^= 1 << i % 5);
      if (++i > 9) {
        printf("%d %d\n", h, b - h);
        memset(R, i = h = b = 0, 232);
      }
    }
  }
  return 0;
}
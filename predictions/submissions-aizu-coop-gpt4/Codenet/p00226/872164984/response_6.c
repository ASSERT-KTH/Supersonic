#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int R[99];
int index, high, base;

int main(int argc, char **argv) {
  int c;
  while (read(0, &c, 1)) {
    base += !!R[c];
    high += !(R[c] ^= 1);
    if (++index > 9) {
      printf("%d %d\n", high, base - high);
      index = high = base = 0;
      memset(R, 0, sizeof(R));
    }
  }
  return 0;
}
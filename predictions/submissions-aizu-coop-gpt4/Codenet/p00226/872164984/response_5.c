#include <stdio.h>
#include <string.h>

char R[99];
int i, h, b;
int main() {
  int c;
  memset(R, 0, 99);  // clear the 'R' array
  while ((c = getchar()) != EOF) {  // read data from the input
    b += !!R[c], h += !(R[c] ^= 1 << i % 5);
    if (++i > 9) {  // print and then clear the variables after every 10 iterations
      printf("%d %d\n", h, b - h);
      i = h = b = 0;
    }
  }
  return 0;
}